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
    int n, C;
    cin >> n >> C;
    vector<vector<PII>> V(n+2);
    set<pair<PII, int>> startTimes;
    vector<PII> recorders;
    REP(i, n) {
        int s, t, c;
        cin >> s >> t >> c;
        // V[c].pb({s, t});
        startTimes.insert({{s, t}, c});
    }
    // debug(startTimes);
    for (auto p : startTimes) {
        if (SZ(recorders) == 0) {
            recorders.pb({p.first.second, p.second});
        } else {
            bool found = false;
            for (int i = 0; i < SZ(recorders); i++) {
                if (recorders[i].second == p.second) {
                    if (recorders[i].first <= p.first.first) {
                        recorders[i].first = p.first.second;
                        recorders[i].second = p.second;
                        found = true;
                        break;
                    }
                } else {
                    if (recorders[i].first < p.first.first) {
                        recorders[i].first = p.first.second;
                        recorders[i].second = p.second;
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                recorders.pb({p.first.second, p.second});
            }
        }
    }
    cout << SZ(recorders) << endl;
}