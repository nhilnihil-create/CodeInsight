#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  ll n;
  cin>>n;
  vector<ll> a(n),b(n),c(n);
  for(auto&& e: a) 
  {
    cin>>e;
  }
  for(auto&& e: b) 
  {
    cin>>e;
  }
  for(auto&& e: c) 
  {
    cin>>e;
  }
  sort(a.begin(),a.end());
  sort(c.begin(),c.end());
  ll ans=0;
  for (int i = 0; i < n; ++i)
  {
    ans+=(lower_bound(a.begin(), a.end(),b[i])
      - a.begin()) *
    (c.end() - upper_bound(c.begin(),
      c.end(),b[i]));
  }
  cout<<ans<<endl;
}