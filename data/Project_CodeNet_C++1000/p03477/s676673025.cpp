#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    
    int x=a+b;
    int y=c+d;
    
    if(x>y){
        cout<<"Left";
    }else if(x==y){
        cout<<"Balanced";
    }else{
        cout<<"Right";
    }
    
    
}
