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
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  REP(i, N) cin >> A[i];
  REP(i, N) cin >> B[i];
  ll hituyou = 0, yoyuu = 0;
  REP(i, N) {
    hituyou += max(0, B[i] - A[i]);
    yoyuu += max(0, A[i] - B[i]);
  }
  if(yoyuu<hituyou){
    cout << -1 << endl;
    return 0;
  }
  ll ans = 0;
  REP(i,N){
    if (A[i] < B[i]) ans++;
  }
  vector<ll> dif(N);
  REP(i, N) { dif[i] = A[i] - B[i]; }
  sort(dif.begin(), dif.end());
  int i = N - 1;
  while(0<hituyou){
    hituyou -= dif[i];
    i--;
    ans++;
  }
  cout << ans << endl;
}