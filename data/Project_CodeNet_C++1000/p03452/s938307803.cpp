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
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
//#define int long long int
const int MOD = 1000000007;
const ll LINF = (ll)1e18 - 1;
const int INF = 1e9 - 1;
const double EPS = 0.000000001;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void print(const vector<int> &v) {
  for(auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<P>> link(n);
  rep(i, m) {
    int l, r, d;
    cin >> l >> r >> d;
    l--; r--;
    link[l].emplace_back(r, d);
    link[r].emplace_back(l, -d);
  }
  VL ans(n, LINF);
  rep(i, n) {
    if(ans[i] == LINF) {
      queue<int> q;
      ans[i] = 0;
      q.push(i);
      while(!q.empty()) {
        int j = q.front();
        q.pop();
        for(auto k : link[j]) {
          if(ans[k.first] == LINF) {
            ans[k.first] = ans[j] + k.second;
            q.push(k.first);
          }
          else if(ans[k.first] != ans[j] + k.second) {
            out("No");
            return 0;
          }
        }
      }
    }
  }
  out("Yes");
  return 0;
}
