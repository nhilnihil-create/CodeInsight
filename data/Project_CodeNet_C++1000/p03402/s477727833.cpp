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
    int A, B;
    cin >> A >> B;
    vector<string> V(100);
    REP(i, 100) {
        REP(j, 100) {
            if (j > 49) {
                V[i].pb('#'); 
            } else {
                V[i].pb('.');
            }
        }
    }
    int cntA = 1;
    int cntB = 1;
    for (int i = 3; i < 90; i+= 3) {
        for (int c = 1, r = i - c; r >= 1; c++, r = i - c) {
            if (cntB >= B) goto done;
            if (c > 46) break;
            V[r][c] = '#';
            cntB++;
        }
    }
    done:
    for (int i = 52; i < 140; i+= 3) {
        for (int c = 52, r = i - c; r >= 1; c++, r = i - c) {
            if (cntA >= A) goto done1;
            if (c > 96) break;
            V[r][c] = '.';
            cntA++;
        }
        // for (int r = 1, c = i - r; c >= 52; r++, c = i - r) {
        //     // if (c < 52) break;
        //     if (cntA >= A) goto done1;
        //     V[r][c] = '.';
        //     cntA++;
        // }
    }
    done1:
    cout << "100 100\n";
    for (string s : V) {
        cout << s << '\n';
    }


}