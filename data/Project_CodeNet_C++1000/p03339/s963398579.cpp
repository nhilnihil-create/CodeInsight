#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (int)(b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define allg(a) (a).begin(), (a).end(), greater<int>()

using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;

const int INF = 1001001001;
const int MOD = 1000000007;
const long long INFL = (1LL << 60);
const double EPS = 1e-9;

int main() {
  int N;
  string S;
  cin >> N >> S;

  vi l(N + 1), r(N + 1);
  rep(i, N) {
    if (S[i] == 'W') {
      l[i + 1] = l[i] + 1;
      r[i + 1] = r[i];
    } else {
      r[i + 1] = r[i] + 1;
      l[i + 1] = l[i];
    }
  }

  int res = INF;
  rep(i, N) res = min(res, l[i] + (r[N] - r[i + 1]));

  cout << res << endl;
}