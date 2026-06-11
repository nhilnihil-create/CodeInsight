#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll f(ll x,ll res)
{
    ll ans=1;
    while(x)
    {
        if(x&1)ans=ans*res;
        res*=res;x/=2;
    }
    return ans;
}
int main()
{
   ll n,p;
   ll ans=1;
   cin>>n>>p;
   if(n==1){cout<<p;return 0;}
   if(p==1){cout<<"1";return 0;}
   if(n>=p){cout<<"1";return 0;}
   if(n>1000000){cout<<"1";return 0;}
   for(ll i=2;;i++)
   {
        ll k=f(n,i);
        if(p<k)break;
         if(p%k==0)ans=i;
   }
   printf("%lld\n",ans);
    return 0;
}
