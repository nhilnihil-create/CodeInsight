#include<iostream>
using namespace std;
int main()
{
    int a,b,c,t=0,i=1;
    cin>>a>>b;
    c=b-a;
    for(i=1;i<=c;i++){
        t=t+i;
    }
    cout<<t-b<<endl;
}