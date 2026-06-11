#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  ll N;
  cin>>N;
  vector<ll> col;
  for(ll i = 0LL; i < N; i++) {
    ll x;
    cin>>x;
    if(i==0) col.push_back(x);
    else if(*(col.end()-1)!=x) col.push_back(x);
  }
  unordered_map<ll,ll> m;
  ll l = col.size();
  vector<ll> dp(l+1,1LL);
  for(ll i = 0; i < l; i++) {
    dp[i+1]=dp[i];
    if(m[col[i]]!=0) dp[i+1]=(dp[i+1]+dp[m[col[i]]])%mod;
    m[col[i]]=i+1;
  }
  cout<<dp[l]<<endl;
}