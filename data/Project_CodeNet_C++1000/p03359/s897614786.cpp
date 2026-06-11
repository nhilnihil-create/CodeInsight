#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    if(a<=b){
        cout<<(min(a,b));
    }
    else
    {
        cout<<(a-1);
    }
    
}