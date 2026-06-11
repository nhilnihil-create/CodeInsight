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
    int N;
    cin >> N;
    vector<ll> V(N + 1);
    REP(i, N) cin >> V[i];
    REP(i, N) {
        vector<__int128_t> VV;
        REP(j, N) {
            // VV.pb(bigint(V[j]));
            VV.pb((__int128_t) V[j]);
        }
        if (i == 0) {
            bool fail = false;
            REP(j, N - 1) {
                VV[j+1] += VV[j];
                VV[j+1] += VV[j];
                if (VV[j+1] < VV[j]) {
                    fail = true;
                    break;
                }
            }
            if (!fail) {
                cout << 2 * (N - 1) << '\n';
                FOR(k, 1, N - 1) {
                    cout << k << " " << k + 1 << '\n';
                    cout << k << " " << k + 1 << '\n';
                }
                return 0;
            }
        } else if (i == N - 1) {
            bool fail = false;
            FORD(j, N - 1, 1) {
                VV[j - 1] += VV[j];
                VV[j - 1] += VV[j];
                    // debug(j-1, j);
                    // debug(VV[j-1], VV[j]);
                if (VV[j - 1] > VV[j]) {
                    fail = true;
                    break;
                }
            }
            if (!fail) {
                cout << 2 * (N - 1) << '\n';
                FORD(k, N, 2) {
                    cout << k << " " << k - 1 << '\n';
                    cout << k << " " << k - 1 << '\n';
                }
                return 0;
            }
        } else {
            if (VV[i] < VV[i - 1]) continue;
            bool fail = false;
            FOR(j, i, N - 2) {
                VV[j+1] += VV[j];
                VV[j+1] += VV[j];
                // debug(V[j + 1], V[j]);
                // debug(VV[j + 1], VV[j]);
                if (VV[j + 1] < VV[j]) {
                    fail = true;
                    break;
                }
            }
            FORD(j, i - 1, 1) {
                VV[j - 1] += VV[j];
                VV[j - 1] += VV[j];
                // debug(VV[j - 1], VV[j]);
                if (VV[j - 1] > VV[j]) {
                    fail = true;
                    break;
                }
            }
            if (!fail) {
                int cnt = 0;
                FOR(k, i + 1, N - 1) cnt += 2;
                FORD(k, i, 2) cnt += 2;
                cout << cnt << '\n';
                FOR(k, i + 1, N - 1) {
                    cout << k << " " << k + 1 << '\n';
                    cout << k << " " << k + 1 << '\n';
                }
                FORD(k, i, 2) {
                    cout << k << " " << k - 1 << '\n';
                    cout << k << " " << k - 1 << '\n';
                }
                return 0;
            }
        }
    }
    cout << 0 << endl;
}