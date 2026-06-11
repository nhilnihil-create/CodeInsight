#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,i,j,k,l,a,b,c,d;
    cin>>a>>b;
    c=0;
    k=a;
    while(k<=b)
    {
        c++;
        k*=2;
    }
    cout<<c<<endl;
}
