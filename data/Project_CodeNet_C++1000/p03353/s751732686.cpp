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
  cin >> s;
  int k;
  cin >> k;
  set<string> tmp;
  rep(i, s.size()) {
    for(int j = i; j <= min((int)s.size() - 1, i + k); ++j) {
      tmp.insert(s.substr(i, j - i + 1));
    }
  }
  auto t = tmp.begin();
  advance(t, k - 1);
  out(*t);

  return 0;
}
