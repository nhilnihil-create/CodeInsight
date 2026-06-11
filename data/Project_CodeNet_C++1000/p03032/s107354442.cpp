#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
using ull = uint64_t;
using ll = int64_t;
using PII = pair<int, int>;
using VI = vector<int>;

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
    ll N, K;
    cin >> N >> K;
    VI V(N);
    REP(i, N) cin >> V[i];
    ll ans = 0;
    // FOR(i, 0, min(N, K)) {
    //     FOR(left, 0, K - i) {
    //         ll sum = 0;
    //         vector<ll> A;
    //         REP(j, left) {
    //             if (j == N) break;
    //             sum += V[j];
    //             A.pb(V[j]);
    //         }
    //         int takeFromR = min({N - left, K - i - left, 0LL});
    //         FORD(j, N - 1, N - takeFromR) {
    //             sum += V[j];
    //             A.pb(V[j]);
    //         }
    //         sort(all(A));
    //         REP(j, i) {
    //             sum -= A[j];
    //         }
    //         ans = max(ans, sum);
    //     }
    // }
    FOR(l, 0, N) {
        FOR(r, 0, N) {
            if (l + r > N) break;
            FOR(i, 0, K) {
                if (l + r + i > K) break;
                if (i > l + r) break;
                vector<ll> A;
                ll sum = 0;
                REP(j, l) {
                    sum += V[j]; 
                    A.pb(V[j]);
                }
                FORD(j, N - 1, N - r) {
                    sum += V[j];
                    A.pb(V[j]);
                }
                sort(all(A));
                REP(j, i) {
                    sum -= A[j];
                }
                ans = max(ans, sum);
            }
        }
    }
    cout << ans << "\n";
}