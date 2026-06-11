#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main() 
{
  ll N,M; cin>>N>>M;
  vector<vector<ll>> s(M,vector<ll>(0));
  rep(i,M)
  {
    ll k; cin>>k;
    rep(j,k)
    {
      ll ss; cin>>ss; ss--;
      s.at(i).push_back(ss);
    }
  }
  vector<ll> p(M);
  rep(i,M)
  {
    cin>>p.at(i);
  }
  
  ll ans=0;
  rep(i,1<<N)
  {
    bitset<10> i2(i);
    bool judge=true;
    rep(j,M)
    {
      ll sum=0;
      for(auto ss:s.at(j))
      {
        if(i2.test(ss)) sum++;
      }
      sum%=2;
      if(p.at(j)!=sum) judge=false;
    }
    if(judge) ans++;
  } 
  cout<<ans<<endl;
  return 0;
}
