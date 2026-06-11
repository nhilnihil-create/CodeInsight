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
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> S, T;
    S.pb(-LLONG_MAX / 10);
    T.pb(-LLONG_MAX / 9);
    ll y;
    REP(i, A) {
    	cin >> y;
    	S.pb(y);
    }
    REP(i, B) {
    	cin >> y;
    	T.pb(y);
    }
    S.pb(LLONG_MAX / 10);
    T.pb(LLONG_MAX / 9);
    vector<ll> V(Q);
    REP(i, Q) cin >> V[i];
    REP(i, Q) {
    	ll x = V[i];
    	ll ans = LLONG_MAX;
    	// going right first
    	auto itS = upper_bound(all(S), x);
    	auto itT = upper_bound(all(T), x);
    	if (*itS < *itT) { // get to a shrine first
    		ll cPos = *itS;
    		auto itT1 = upper_bound(all(T), cPos);
    		auto itT2 = prev(itT1);
    		ll q = min(abs(*itT1 - cPos), abs(*itT2 - cPos));
    		ans = min(ans, q + cPos - x);
    	}
        else if (*itT < *itS) { // get to a temple first
    		ll cPos = *itT;
    		auto itS1 = upper_bound(all(S), cPos);
    		auto itS2 = prev(itS1);
    		ll q = min(abs(*itS1 - cPos), abs(*itS2 - cPos));
    		ans = min(ans, q + cPos - x);
    	}
    	// going left
    	auto itSl = prev(itS);
    	auto itTl = prev(itT);
    	if (*itSl > *itTl) {
    		ll cPos = *itSl;
    		auto itT1 = upper_bound(all(T), cPos);
    		auto itT2 = prev(itT1);
    		ll q = min(abs(*itT1 - cPos), abs(*itT2 - cPos));
    		ans = min(ans, q + x - cPos);
    	}
        else if (*itTl > *itSl) { // get to a temple first
    		ll cPos = *itTl;
    		auto itS1 = upper_bound(all(S), cPos);
    		auto itS2 = prev(itS1);
    		ll q = min(abs(*itS1 - cPos), abs(*itS2 - cPos));
    		ans = min(ans, q + x - cPos);
    	}
    	cout << ans << '\n';
    }
}