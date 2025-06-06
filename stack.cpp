#include<iostream>
using namespace std;

class StackOverFlow:exception{};
class StackUnderFlow: exception{};

class Stack{
    private:
        int *stk;  
        int top = -1;
        int size;
    public: 
        Stack(int sz){
            size = sz;
            stk = new int[size];
        }
        void push(int x){              // add element: throw if full
            if(top == size-1)
                throw StackOverFlow();
            top++;
            stk[top] = x;
        }
        int pop(){                     // remove element: throw if empty
            if(top == -1)
                throw StackUnderFlow();
            return stk[top--];
        }
};

int main(){
    Stack s(5);
    try{
        s.push(1);
        s.push(6);
        s.push(4);
        s.push(10);
        s.push(8);
        s.push(14); //throws overflow
    }
    catch(StackOverFlow &e){
        cout<<"StackOverFlow Error"<<endl;
    }
    catch(StackUnderFlow &e){
        cout<<"StackUnderFlow Error"<<endl;
    }
    
    
}

