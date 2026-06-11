#include<iostream>
using namespace std;
int main()
{
    long long n,s=0,i=0,b;
    cin>>n;
    for(i=0;i<n;i++)
    {cin>>b;
    s+=b;
}cout<<s-n;
}