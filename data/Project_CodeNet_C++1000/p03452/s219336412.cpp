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

vector< vector<PII> > G, G1;
bool visited[100004], visited1[100005];
int dist[100005];
bool fail;

void dfs1(int v);

void dfs(int v) {
    if (visited[v]) return;
    visited[v] = true;
    for (auto p : G[v]) {
        if (dist[p.first] != -1) {
            if (dist[p.first] != dist[v] + p.second) {
                fail = true;
                return;
            }
        } else {
            dist[p.first] = dist[v] + p.second;
            dfs(p.first);
            dfs1(p.first);
        } 

    }

}

void dfs1(int v) {
    if (visited1[v]) return;
    visited1[v] = true;
    for (auto p : G1[v]) {
        if (dist[p.first] != -1) {
            if (dist[p.first] != dist[v] - p.second) {
                fail = true;
                return;
            }
        } else {
            dist[p.first] = dist[v] - p.second;
            dfs1(p.first);
            dfs(p.first);
        }
    }
}


int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N, M;
    cin >> N >> M;
    G.assign(N + 3, vector<PII>());
    G1.assign(N + 3, vector<PII>());
    REP(i, M) {
        int l, r, d;
        cin >> l >> r >> d;
        G[r].pb({l, d});
        G1[l].pb({r, d});
    }
    memset(dist, -1, sizeof(dist));
    FOR(i, 1, N) {
        if (dist[i] == -1) {
            dist[i] = 0;
        }
        if (!visited1[i]) {
            dfs1(i);
        }
        if (!visited[i]) {
            dfs(i);
        }
    }
    if (fail) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }

}