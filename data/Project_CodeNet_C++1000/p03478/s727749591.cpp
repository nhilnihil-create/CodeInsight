#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i = ll(a); i <= ll(b); i++)
int main()
{
    ll a,b,n,r=0;
    cin>>n>>a>>b;
    REP(i,1,n)
    {
        ll c=0,t=i;
        REP(j,0,5)
        {
            c+=t%ll(10);
            t/=10;
        }
        if(a<=c && c<=b)
            r+=i;
}
    cout<<r;        
}