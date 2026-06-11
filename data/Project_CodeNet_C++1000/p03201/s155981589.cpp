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

int main(void) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];

    multiset<ll> st;
    REP(i, n) st.insert(a[i]);

    ll t = 2;
    vector<ll> p;
    while(t < (1LL<<31)) {
        p.push_back(t);
        t *= 2;
    }

    ll ret = 0;
    while(st.size()>=2) {
        ll x = *st.rbegin();
        st.erase(st.find(x));
        REP(i, p.size()) {
            auto itr = st.find(p[i]-x);
            if(itr == st.end()) continue;

            ret++;
            st.erase(itr);
            break;
        }
    }

    cout << ret << endl;

    return 0;
}