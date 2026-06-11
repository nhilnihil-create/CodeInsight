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

int N, M;
VI G[100005];
bool visited[100005];

void dfs(int v) {
    if (visited[v]) return;
    visited[v] = true;
    for (int u : G[v]) {
        dfs(u);
    }
}


int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> N >> M;
    REP(i, M) {
    	ll x, y, w;
    	cin >> x >> y >> w;
    	G[x].push_back(y);
    	G[y].push_back(x);
    }
    int ans = 0;
    FOR(i, 1, N) {
        if (!visited[i]) {
            dfs(i);
            ans++;
        }
    }
    cout << ans << "\n";

}
