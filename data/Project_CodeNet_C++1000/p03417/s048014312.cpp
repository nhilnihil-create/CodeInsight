#include<iostream>
using namespace std;
#define ll long long

void Main()
{
    ll n,m;
    cin>>n>>m;
    ll s;
    if(n>1&&m>1)s=m+m+n+n-4;
    else if(m==1&&n==1)s=0;
    else s=2;
    cout<<n*m-s;
}
int main()
{
Main();
return 0;
}