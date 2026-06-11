#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define trav(a, x) for (auto& a : x)
using ull = uint64_t;
using ll = int64_t;
using PII = pair<int, int>;
using VI = vector<int>;
#define INF (1ll<<60)

string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(A v) {
bool first = true; string res = "{";
for (const auto &x : v) { if (!first) { res += ", "; } first = false; res += to_string(x); }
res += "}"; return res; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H); debug_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<pair<ll, ll>> V(N);
    REP(i, N) {
        int x, y;
        cin >> x >> y;
        V[i] = {x, y};
    }
    sort(all(V));
    ll ans = LLONG_MAX;
    REP(i, N - 1) {
        FOR(j, i + 1, N - 1) {
            vector<ll> A;
            FOR(k, i, j) {
                A.pb(V[k].second);
            }
            sort(all(A), greater<ll>());
            REP(k, SZ(A) - 1) {
                FOR(l, k + 1, SZ(A) - 1) {
                    if (l - k + 1 < K) continue;
                    ll mxY = max(max(V[i].second, V[j].second), max(A[k], A[l]));
                    ll mnY = min(min(V[i].second, V[j].second), min(A[k], A[l]));
                    ll area = abs(V[i].first - V[j].first) * (mxY - mnY);
                    ans = min(area, ans);
                }
            }
        }
    }
    cout << ans << endl;
}