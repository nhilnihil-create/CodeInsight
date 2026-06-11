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
  int N, x;
  cin >> N >> x;
  vector<int> a(N);
  REP(i, N) cin >> a[i];
  sort(a.begin(), a.end());
  int i = 0;

  while (0 < x&&i<N) {
    x -= a[i];
    i++;
  }
  if (x != 0) i--;
  cout << i << endl;
}