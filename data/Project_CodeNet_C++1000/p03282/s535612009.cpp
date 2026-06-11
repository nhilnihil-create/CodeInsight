#define _DEBUG 1
#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#ifdef _DEBUG
#define dump(x) cerr << #x << "=" << x << endl
#define dump2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define dump3(x, y, z)                                                     \
  cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z \
       << endl
#define check(s) cerr << s << endl
#else
#define dump(x)
#define dump2(x, y)
#define dump3(x, y, z)
#define check(s)
#endif

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

const ll LINF = 2e18;
const int INF = 1e9;

void solve(string S, ll K) {
  bool allOne = true;
  char c;
  rep(i, K) {
    if (S.at(i) != '1') {
      allOne = false;
      c = S.at(i);
      break;
    }
  }

  if (allOne)
    cout << 1 << endl;
  else
    cout << c << endl;
}

int main() {
  string S;
  cin >> S;
  ll K;
  cin >> K;
  solve(S, K);
  return 0;
}
