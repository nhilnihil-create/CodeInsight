#include <iostream>
using namespace std;
int main(void){
    int a,b;
    cin>>a>>b;
    if (a+b==15){
        cout<<"+";
    }
    else if (a*b==15){
        cout<<"*";
    }
    else{
        cout<<"x";
    }
}
