#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ash[100001];
ll ans=0;
ll f(ll a[],ll start,ll size,ll k)
{
   if(start==size-1)
   return 0;
   if(ash[start]!=-1)
   return ash[start];
   ll cost=f(a,start+1,size,k)+abs(a[start]-a[start+1]);
    for(int i=2;i<=k;i++)
                 {
                  if(start+i<size) 
   cost=min(cost,(f(a,start+i,size,k)+abs(a[start]-a[start+i])));
                 }
     return ash[start]=cost;
}
int main()
{
    memset(ash,-1,sizeof(ash));
  ll n,k;
  cin>>n>>k;
  ll a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  ll start=0,ans1;
  ans1=f(a,start,n,k);
  cout<<ans1;
  
}
  