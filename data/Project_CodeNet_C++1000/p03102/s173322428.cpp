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
  int N, M, C;
  cin >> N >> M >> C;
  vector<int> B(M);
  vector<vector<int>> A(N, vector<int>(M));
  REP(i, M) cin >> B[i];
  REP(i, N) REP(j, M) cin >> A[i][j];
  ll ans = 0;
  REP(i, N) { ll num = 0;
    REP(j, M) { num += A[i][j] * B[j]; }
    num += C;
    if(num>0){
      ans++;
    }
   }
   cout << ans << endl;
}