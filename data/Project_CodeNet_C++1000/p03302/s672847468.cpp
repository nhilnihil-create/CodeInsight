#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int n,i;
    cin>>n>>i;
    if(n+i==15)
    cout<<"+"<<endl;
    if(n*i==15)
    cout<<"*"<<endl;
    if(n+i!=15&&n*i!=15)
    cout<<"x"<<endl;
    return 0;
}