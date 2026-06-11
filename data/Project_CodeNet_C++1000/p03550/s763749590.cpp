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

// int dp[2005][2];

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, Z, W;
    cin >> n >> Z >> W;
    VI V(n+1);
    FOR(i, 1, n) {
        cin >> V[i];
    }
    if (n == 1) {
        cout << abs(V[1] - W) << endl;
    } else if (n == 2) {
        cout << max(abs(V[n] - W), abs(V[n - 1] - W)) << endl;
    } else {
        // dp[n - 1][0] = abs(V[n] - V[n - 1]);
        // dp[n - 1][1] = dp[n - 1][0];
        int mn = abs(V[n] - V[n - 1]);
        int mx = abs(V[n] - V[n - 1]);
        int ans = abs(V[n] - V[n - 1]);
        // dp[n - 2][1] = max(abs(V[n] - V[n - 2]), dp[n - 1][0]);
        for (int i = n - 2; i >= 1; i--) {
            // int mx = 0;
            // for (int j = i + 1; j <= n - 1; j++) {
            //     mx = max(mx, dp[j][0]);
            // }
            int dp = max(mx, abs(V[n] - V[i]));
            mx = max(dp, mx);
            // int mn = INT_MAX;
            // for (int j = i + 1; j <= n - 1; j++) {
                // mn = min(mn, dp[j][1]);
            // }
            dp = min(mn, abs(V[n] - V[i]));
            mn = min(mn, dp);
            ans = max(ans, dp);
        }
        // for (int i = 1; i < n; i++) {
        //     cout << dp[i][0] <<" "<<  dp[i][1] << endl;
        // }
        // int ans = 0;
        // for (int i = 1; i < n; i++) {
        //     ans = max(ans, dp[i][0]);
        // }
        cout << max(abs(V[n] - W), ans) << endl;
    }
}