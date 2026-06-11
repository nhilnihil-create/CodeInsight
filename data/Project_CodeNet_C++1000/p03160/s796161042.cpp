#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ash[100001];
ll ans=0;
ll f(ll a[],ll start,ll size)
{
   if(start==size-1)
   return 0;
   if(ash[start]!=-1)
   return ash[start];
   ll cost=f(a,start+1,size)+abs(a[start]-a[start+1]);
   if(start+2<size)
   cost=min(cost,(f(a,start+2,size)+abs(a[start]-a[start+2])));
     return ash[start]=cost;
}
int main()
{
    memset(ash,-1,sizeof(ash));
  ll n;
  cin>>n;
  ll a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  ll start=0,ans1;
  ans1=f(a,start,n);
  cout<<ans1;
  
}
  