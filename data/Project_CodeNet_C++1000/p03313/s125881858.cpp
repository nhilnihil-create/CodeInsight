#pragma target("avx")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef unordered_map<ll, ll> U_MAP;
typedef priority_queue<ll> pq;
typedef priority_queue<ll, vector<ll>, greater<ll>> rpq;
const int INF = 1e9, MOD = 1e9 + 7, ohara = 1e6 + 10;
const ll LINF = 1e18;

#define rep(i, n) for (ll(i) = 0; (i) < (int)(n); (i)++)
#define rrep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrrep(i, a, b) for (ll i = (a); i >= (b); i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout << (x) << endl
#define doublecout(a) cout << fixed << setprecision(15) << a << endl;
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

//------ Believe yourself as a genius!!!!!! ------

struct pair_equal {
  bool operator()(const pair<ll, ll>& x, const pair<ll, ll>& y) const {
    return x.se == y.se;
  }
};

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
// int dy[]={-1,0,1,-1,1,-1,0,1};int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"), s;
ll n, cnt, ans, a[ohara], b, c, d, tmp, m, h, w, x, y, sum, k, q;
pair<pair<ll, ll>, pair<ll, ll>> dp[ohara];

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  // dp[i]={i, j, index_i, index_j}
  cin >> n;
  ll length = (1LL << n);
  rep(i, length) {
    cin >> a[i];
    dp[i] = m_p(m_p(a[i], 0), m_p(i + 1, -1));
  }

  rep(i, length) {
    rep(j, n) {
      if (i & (1LL << j)) continue;
      vector<P> sorted;
      sorted.p_b({dp[i].fi.fi, dp[i].se.fi});
      sorted.p_b({dp[i].fi.se, dp[i].se.se});
      sorted.p_b({dp[(i | (1LL << j))].fi.fi, dp[(i | (1LL << j))].se.fi});
      sorted.p_b({dp[(i | (1LL << j))].fi.se, dp[(i | (1LL << j))].se.se});
      sort(all(sorted));
      reverse(all(sorted));
      sorted.erase(unique(all(sorted), pair_equal()), sorted.end());
      dp[(i | (1LL << j))] =
          m_p(m_p(sorted[0].fi, sorted[1].fi), m_p(sorted[0].se, sorted[1].se));
    }
  }
  rrep(i, 1, length) {
    ans = max(ans, dp[i].fi.fi + dp[i].fi.se);
    Cout(ans);
  }
  return 0;
}