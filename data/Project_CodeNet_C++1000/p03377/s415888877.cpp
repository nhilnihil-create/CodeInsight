#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,x;
    cin>>a>>b>>x;
    if(x-a<0)
    cout<<"NO"<<endl;
    else if(a+b<x)
    cout<<"NO"<<endl;
    else
    cout<<"YES"<<endl;
}