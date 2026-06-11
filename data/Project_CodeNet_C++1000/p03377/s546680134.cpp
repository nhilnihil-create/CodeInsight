#include<iostream>
using namespace std;
int main(){
    int a,b,x;
    cin>>a>>b>>x;
    if(x<a)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        x-=a;
        if(b>x){
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}