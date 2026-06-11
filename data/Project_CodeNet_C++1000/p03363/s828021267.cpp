#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

constexpr int INF = 1e9;
// constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N){
    cin >> A[i];
  }
  vector<ll> sum(N+1, 0);
  map<ll, int> mp;
  REP(i, N){
    sum[i+1] = A[i] + sum[i];
    mp[sum[i+1]]++;
  }
  mp[0]++;
  ll ans = 0;
  for(auto m : mp){
    ans += (ll)m.second * (m.second-1)/2;
  }
  cout << ans << endl;
  return 0;
}
