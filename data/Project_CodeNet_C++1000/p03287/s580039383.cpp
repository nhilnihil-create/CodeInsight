#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

constexpr int INF = 1e9;
//constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;


int main(){
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  vector<ll> sum(N+1, 0);
  REP(i, N){
    cin >> A[i];
  }
  map<int, int> mp;
  mp[0]++;
  REP(i, N){
    sum[i+1] = sum[i] + A[i];
    sum[i+1] %= M;
    mp[sum[i+1]]++;
  }
  ll ans = 0;
  for(auto pr : mp){
    ans += (ll)pr.second * (pr.second-1)/2;
  }
  cout << ans << endl;
  return 0;
}
