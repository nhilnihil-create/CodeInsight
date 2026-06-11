#include<iostream>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int left=a+b;
    int right=c+d;
    if(left>right)
    {
        cout<<"Left\n";
    }
    else
    if(left<right){
        cout<<"Right\n";
    }
    else
    {
        cout<<"Balanced\n";
    }
}