#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vs = vector<string>;
using vp = vector<pii>;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (ll)((x).size())
#define all(x) (x).begin(), (x).end()
#define each(a, x) for (auto&& a : (x))
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, n) for (ll i = (a); i < (n); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep)(__VA_ARGS__)
#define _per(i, n) peri(i, 0, n)
#define peri(i, a, n) for (ll i = (n) - 1; i >= (a); --i)
#define per(...) _overload3(__VA_ARGS__, peri, _per)(__VA_ARGS__)
const int INF = 1e9;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
template<typename T> inline void chmax(T& a, const T& b) {if (a < b) a = b;}
template<typename T> inline void chmin(T& a, const T& b) {if (a > b) a = b;}
template<typename T> inline void print(const T& x) {cout << x << "\n";}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p) {is >> p.fi >> p.se; return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {os << p.fi << " " << p.se; return os;}
template<typename T> istream& operator>>(istream& is, vector<T>& v) {each(in, v) is >> in; return is;}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {rep(i, sz(v)) {os << v[i] << (i + 1 != sz(v) ? " " : "");} return os;}
struct Init {Init() {ios::sync_with_stdio(false); cin.tie(0); cout << fixed << setprecision(10);}} init;

int main() {
    ll n, m; cin >> n >> m;
    vi p(m), y(m);
    rep(i, m) {
        cin >> p[i] >> y[i];
        --p[i];
    }
    vvi vals(n);
    rep(i, m) vals[p[i]].pb(y[i]);
    rep(i, n) sort(all(vals[i]));
    rep(i, m) {
        ll v = p[i];
        printf("%06d", v + 1);
        ll id = lower_bound(all(vals[v]), y[i]) - vals[v].begin();
        printf("%06d\n", id + 1);
    }
}