#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

ll solve(ll C, const vector<pair<ll,ll>>& v){
  int N = v.size();
  ll ret = 0;
  vector<ll> dp(N, 0);

  ll sum = 0, mxdp = 0;
  rep(i,N){
    sum += v[i].second;
    ret = max(ret, sum - v[i].first);
    dp[i] = mxdp = max(mxdp, sum - (2*v[i].first));
  }

  sum = 0;
  for(int i=N-1; i>=0; i--){
    sum += v[i].second;
    ll dist = C - v[i].first;
    ll best = ((i<=0)?0:dp[i-1]) + sum - dist;
    ret = max(ret, best);
  }

  return ret;
}

int main(){
  int N;
  ll C;
  cin >> N >> C;
  vector<pair<ll,ll>> v,w;
  rep(i,N){
    ll a, b;
    cin >> a >> b;
    v.emplace_back(a,b);
    w.emplace_back(C-a,b);
  }
  reverse(ALLOF(w));
  
  ll ret = 0;
  ret = max(ret, solve(C, v));
  ret = max(ret, solve(C, w));

  cout << ret << endl;
  
  return 0;
}
