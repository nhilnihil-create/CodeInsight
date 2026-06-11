#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define fout(x) cout << fixed << setprecision(20) << x << endl
const int MOD = 1e9 + 7;
const ll LINF = (ll)1e18 - 1;
const int INF = 1e9 - 1;
const double EPS = 1e-8;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

auto print = [](auto &v) {
  for(auto x : v) {
    cout << x << " ";
  }
  cout << endl;
};

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  int x, y;
  cin >> s;
  cin >> x >> y;
  bool is_first = true;
  bool is_x = true;
  vector<vector<bool>> dpx(s.size() + 10, vector<bool>(20000, false)), dpy(s.size() + 10, vector<bool>(20000, false));
  dpx[0][10000] = true;
  dpy[0][10000] = true;
  int move = 0;
  VI vec_move;
  rep(i, s.size()) {
    if(s[i] == 'F') move++;
    else {
      vec_move.push_back(move);
      move = 0;
    }
    if(i == s.size() - 1) vec_move.push_back(move);
  }
  rep(i, vec_move.size()) rep(j, 20000) {
    int m = vec_move[i];
    if(i % 2 == 0) {
      if(i == 0 && j + m < 20000) {
        dpx[i + 1][j + m] = dpx[i + 1][j + m] | dpx[i][j];
      }
      else {
        if (j + m < 20000) dpx[i + 1][j + m] = dpx[i + 1][j + m] | dpx[i][j];
        if (j - m >= 0) dpx[i + 1][j - m] = dpx[i + 1][j - m] | dpx[i][j];
      }
      dpy[i + 1][j] = dpy[i][j];
    }
    else {
      if (j + m < 20000) dpy[i + 1][j + m] = dpy[i + 1][j + m] | dpy[i][j];
      if (j - m >= 0) dpy[i + 1][j - m] = dpy[i + 1][j - m] | dpy[i][j];
      dpx[i + 1][j] = dpx[i][j];
    }
  }

  string ans = dpx[vec_move.size()][x + 10000] & dpy[vec_move.size()][y + 10000] ? "Yes" : "No";
  out(ans);

  return 0;
}
