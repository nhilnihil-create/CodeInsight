#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  ll N, M;
  cin >> N >> M;
  vector<pair<ll,ll>> A(N);
  REP(i, N) cin >> A[i].first >> A[i].second;
  sort(A.begin(), A.end());
  ll ans = 0;
  REP(i,N){
    if (M == 0) break;
    if(M<=A[i].second){
      ans += A[i].first * M;
      M = 0;
    }else{
      ans += A[i].first * A[i].second;
      M -= A[i].second;
    }
  }
  cout << ans << endl;
}