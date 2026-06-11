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
//#define int long long int
const int MOD = 1000000007;
const ll LINF = (ll)1e18 - 1;
const int INF = 1e9 - 1;
const double EPS = 0.000000001;
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
  ll m, k;
  cin >> m >> k;
  VL ans;
  if(k >= pow(2, m)) {
    out(-1);
  }
  else if(m == 0 && k == 0) {
    cout << 0 << ' ' << 0 << endl;
  }
  else if(m == 1 && k == 1) {
    out(-1);
  }
  else if(m == 1 && k == 0) {
    cout << 0 << ' ' << 0 << ' ' << 1  << ' ' << 1 << endl;
  }
  else {
    for(int i = 0; i < pow(2, m); ++i) {
      if(i != k) ans.push_back(i);
    }
    ans.push_back(k);
    for(int i = (int)pow(2, m) - 1; i >= 0; --i) {
      if(i != k) ans.push_back(i);
    }
    ans.push_back(k);
    print(ans);
  }
  return 0;
}
