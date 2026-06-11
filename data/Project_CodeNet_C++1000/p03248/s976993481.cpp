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

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
// int dy[]={-1,0,1,-1,1,-1,0,1};int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"), s;
ll n, cnt, a, b, c, d, tmp, m, h, w, x, y, sum, k, q;
vector<P> ans;

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  cin >> s;

  if (s[Size(s) - 1] == '1' || s[0] == '0') {
    Cout(-1);
    return 0;
  }
  rep(i, Size(s) - 1) {
    if (s[i] == s[Size(s) - i - 2]) continue;
    Cout(-1);
    return 0;
  }
  ll now = 0;
  rep(i, Size(s) - 1) {
    if (s[i] == '1') {
      ans.p_b({now, now + 1});
      now++;
    } else {
      cnt = 0;
      while (1) {
        if (s[i] == '0')
          cnt++, i++;
        else {
          break;
        }
      }
      ll to = now + 1;
      rep(j, cnt) {
        ans.p_b({now, to});
        to++;
      }
      ans.p_b({now, to});
      now = to;
    }
  }
  rep(i, Size(s) - 1) { cout << ans[i].fi + 1 << " " << ans[i].se + 1 << "\n"; }
  return 0;
}