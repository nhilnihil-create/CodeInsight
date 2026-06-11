#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll bc(ll i)
{
    if(i==0)
    return 1;
    ll st=1;
    for(ll j=1;j<=i;j++)
    st*=2;
    return st;
}
void solve()
{
   
       ll n,k;
       cin>>n>>k;
       ll ans=INT_MAX;
       for(ll i=0;i<=n;i++)
       {
           ll bc1=bc(i);
           ll sm=k*(n-i);
           ans=min(ans,bc1+sm);
            
       }
      
       cout<<ans<<endl;
}

int main()
{
  ll t;
  //cin>>t;
  t=1;
  while(t--)
  {
      solve();
  }
   
   
   
}