#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, e) for (int i = s; i < e; ++i)
#define sort_(a) stable_sort(a.begin(), a.end())
#define rsort(a) stable_sort(a.rbegin(), a.rend())
#define sum(a) accumulate(a.begin(), a.end(), 0LL)
#define join(a, d) accumulate(a.begin() + 1, a.end(), a[0], [](string s, string t) {return s + d + t;})
#define all(a) a.begin(), a.end()
#define __lcm(a, b) std::__detail::__lcm(a, b)
typedef long long ll;
const long mod = 1e9 + 7;

int main(void) {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int H, W;
  cin >> H >> W;
  vector<string> S(H + 2);
  S[0] = string(W + 2, '@');
  S[H+1] = string(W + 2, '@');
  rep(i, 1, H + 1) {
    cin >> S[i];
    S[i] = '@' + S[i] + '@';
  }
 
  vector<string> g(H + 2);
  g[0] = string(W + 2, '@');
  g[H+1] = string(W + 2, '@');
  rep(i, 1, H + 1) {
    g[i] = '@' + string(W, '.') + '@';
  }

  rep(i, 1, H + 1) {
    rep(j, 1, W + 1) {
      if (S[i][j] == '#') {
        int d[] = {0, 1, 0, -1};
        int nx, ny;
        int n = 0;
        rep(k, 0, 4) {
          nx = i + d[k];
          ny = j + d[k^1];
          if (S[nx][ny] == '#') {
            g[nx][ny] = '#';
            ++n;
          }
        }
        if (n) S[i][j] = '#';
      }
    }
  }

  rep(i, 1, H + 1) {
    if (S[i] != g[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
