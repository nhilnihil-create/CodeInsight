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
    int N, C;
    cin >> N >> C;
    vector<VI> grid(N, VI(N));
    vector<VI> D(C, VI(C));
    REP(i, C) {
        REP(j, C) cin >> D[i][j];
    }
    REP(i, N) {
        REP(j, N) {
            cin >> grid[i][j];
            grid[i][j]--;
        }
    }
    vector<unordered_map<int, int>> V(3); 
    REP(i, N) {
        REP(j, N) {
            int k = (i + j) % 3;
            V[k][grid[i][j]]++;
        }
    }
    int ans = INT_MAX;
    FOR(i, 0, C - 1) {
        FOR(j, i + 1, C - 1) {
            FOR(k, j + 1, C - 1) {
                VI A{i, j, k};
                do {
                    int sum = 0;
                    for (int l = 0; l < 3; l++) {
                        for (auto p : V[l]) {
                            sum += D[p.first][A[l]] * p.second;
                        }
                    }
                    ans = min(ans, sum);
                } while (next_permutation(all(A)));
            }
        }
    }
    cout << ans << endl;

}