#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
const int inf = 1e9 + 7;
const ll INF = 1e18;
#define abs(x) (x >= 0 ? x : -(x))
#define lb(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define ub(v, x) (int)(upper_bound(all(v), x) - v.begin())
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> T pow(T a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
const int mod = 1000000007;
ll modpow(ll a, int b) { return b ? modpow(a * a % mod, b / 2) * (b % 2 ? a : 1) % mod : 1; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { rep(i, sz(v)) { if (i) os << " "; os << v[i]; } return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p) { os << p.F << " " << p.S; return os; }
template<class T> inline void add(T &a, int b) { a += b; if (a >= mod) a - mod; }

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    // cin >> T;
    T = 1;

    while (T--) {
      solve();
    }
}


string s, t;

bool check(int x) {
    cin >> t;
    if (t[0] == 'V') exit(0);

    if (x % 2 == 0 && t[0] != s[0]) return 0; // debuged, 'F' to s[0]
    if (x % 2 && t[0] == s[0]) return 0;

    return 1;
}

template<typename T>
void binary_search(T ok, T ng) {
    while (abs(ng - ok) > 1) {
        T mid = (ng + ok) / 2;
        cout << mid << endl;
        (check(mid) ? ok : ng) = mid;
    }
}

void solve() {
  int n;
  cin >> n;
  if (n <= 20) {
    rep(i, n) {
      cout << i << endl;
      string s;
      cin >> s;
      if (s[0] == 'V') return;
    }
  }

  cout << 0 << endl;
  cin >> s;
  if (s[0] == 'V') return;

  binary_search(0, n);
}
