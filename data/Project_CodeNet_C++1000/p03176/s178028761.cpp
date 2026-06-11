#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long  
using namespace std;
#define  inf 1e18+18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007
#define  f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n)  for(i=0;i<n;i++)
#define w(x)   while(x--)
const int maxn=1000001;
#define  pq priority_queue
#define  ff first
#define  ss second 
#define pb  push_back
#define lb lower_bound
int main()
{
   
   ll i,j,k,l,m,n;
   cin>>n;
   ll a[n],b[n];
   for(i=0;i<n;i++)
   	cin>>a[i];
   for(i=0;i<n;i++)
   	cin>>b[i];
   map<ll,ll>mp;
   ll dp[n];
   ll ans=b[0];
   dp[0]=b[0];
   mp[a[0]]=dp[0];
   for(i=1;i<n;i++)
   {
    dp[i]=b[i];
    auto it=mp.lb(a[i]);
    if(it!=mp.begin())
    {
    	it--;
    	dp[i]+=it->second;
    }
    mp[a[i]]=dp[i];
    auto itr=mp.upper_bound(a[i]);
    while(itr!=mp.end()&&itr->ss<=dp[i])
    {
    	auto temp=itr;
    	temp++;
    	mp.erase(itr);
    	itr=temp;
    }
    ans=max(ans,dp[i]);

   }
   cout<<ans;

   
}