#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
struct FastIO {FastIO() { cin.tie(0); ios::sync_with_stdio(0); }}fastiofastio;
#ifdef DEBUG
#include "../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
const ll INF = 1LL<<60;

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if(a < b || d < b) {
        cout << "No" << endl;
        return;
    }

    if(c >= b-1) {
        cout << "Yes" << endl;
        return;
    }

    ll g = __gcd(b, d);
    if(b-c-1>=g) {
        cout << "No" << endl;
        return;
    }

    ll k = (c-a)/g+1;
    dump(a, b, c, d);
    dump(g, k, k*g+a);
    FOR(i, k-5, k+5) {
        if(c < i*g+a && i*g+a < b) {
            cout << "No" << endl;
            return;
        } 
    }
    cout << "Yes" << endl;
}

int main(void) {
    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}