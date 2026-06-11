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
    ll n;
    cin >> n;
    vector<ll> pos, neg;
    int tries = 22;
    for (int i = 0; i < (1 << tries); i++) {
        ll k = 0;
        for (int j = 0; j < tries; j++) {
            if (i & (1 << j)) {
                k |= (1LL << (2 * j));
            }
        }
        pos.pb(k);
    }
    for (int i = 0; i < (1 << tries); i++) {
        ll k = 0;
        for (int j = 0; j < tries; j++) {
            if (i & (1 << j)) {
                k |= (1LL << (2 * j + 1));
            }
        }
        neg.pb(k);
    }
    for (ll p : pos) {
        ll k = p - n;
        auto it = lower_bound(all(neg), k);
        if (it != neg.end() && *it == k) {
            ll ans = p | k;
            string s = std::bitset<64>(p | k).to_string();
            while (SZ(s) > 1 && *(s.begin()) == '0') {
                s.erase(s.begin());
            }
            cout << s << endl;
            return 0;
        }
    }
}