#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long i,j,t,a,b,n,c,d,y,temp,m,r,sum,count,k,l,ans;
    t=1;
    // cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ans=(n-m)*100+(m)*1900;
        ans*=pow(2,m);
        cout<<ans;
    }
}