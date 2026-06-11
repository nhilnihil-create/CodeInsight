#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod=1e9+7;

int main()
{
  int n;
  cin>>n;
  vector<ll> h(n),b(n),dp(n);
  for(ll& x:h)
  cin>>x;
  for(ll&x: b)
  cin>>x;
  dp[0]=b[0];
  map<ll,ll> mp;
  mp[h[0]]=dp[0];
  for(int i=1;i<n;i++)
  {
    dp[i]=b[i];
    auto it=mp.lower_bound(h[i]);
    if(it!=mp.begin())
    {
      it--;
      dp[i]+=it->second;
    }
    mp[h[i]]=dp[i];
    it=mp.upper_bound(h[i]);
    while(it!=mp.end()&&it->second<=dp[i])
    {
      auto temp=it;
      it++;
      mp.erase(temp);
    }
  }
  cout<<*max_element(dp.begin(),dp.end())<<endl;
  return 0;
}