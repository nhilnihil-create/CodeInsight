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
  int N, M, X;
  cin >> N >> M >> X;
  vector<int> A(N + 1, 0);
  REP(i, M) {
    int a;
    cin >> a;
    A[a] = 1;
  }
  ll to0 = 0;
  for (int i = X; i > 0; i--) to0 += A[i];
  ll toN1 = 0;
  for (int i = X; i<=N ; i++) toN1 += A[i];
  cout << min(to0, toN1) << endl;
}