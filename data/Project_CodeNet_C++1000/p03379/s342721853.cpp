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
  vector<P> X(N);
  vector<int> A(N);
  REP(i, N) {
    cin >> X[i].first;
    X[i].second = i;
    A[i] = X[i].first;
  }
  sort(X.begin(), X.end());
  int div = (N) / 2;
  REP(i, N) {
    if (X[div].first > A[i]) {
      cout << X[div].first << endl;
    } else {
      cout << X[div - 1].first << endl;
    }
  }
}