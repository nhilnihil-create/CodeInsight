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
    int N, M;
    cin >> N >> M;
    vector<vector<ll>> V(N);
    REP(i, N) {
        ll x, y, z;
        cin >> x >> y >> z;
        V[i] = {x, y, z};
    }
    vector<VI> S{{0, 0, 0}, {0, 0, 1} , {0, 1, 0}, {0, 1, 1}, {1, 0, 0}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1}};
    ll ans = 0;
    for (auto v : S) {
        sort(all(V), [v](auto a, auto b) {
            ll sumA = 0;
            ll sumB = 0;
            REP(i, 3) {
                if (v[i] == 0) {
                    sumA += a[i];
                    sumB += b[i];
                } else {
                    sumA += -a[i];
                    sumB += -b[i];
                }
            }
            return sumA > sumB;
        });
        vector<ll> sum{0, 0, 0};
        REP(i, M) {
            sum[0] += V[i][0];
            sum[1] += V[i][1];
            sum[2] += V[i][2];
        }
        ans = max(ans, abs(sum[0]) + abs(sum[1]) + abs(sum[2]));
    }
    cout << ans << endl;

}