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
#ifdef DEBUG_ 
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

    ll cur = 0, nxt = 1;
    vector<bitset<4000010>> bs(2);
    bs[cur][0] = 1;
    REP(i, n) {
        bs[nxt] = bs[cur] | (bs[cur] << a[i]);
        swap(cur, nxt);
    }
    
    ll sum = 0;
    REP(i, n) sum += a[i];
    FOR(i, (sum+1)/2, 4000010) if(bs[cur][i]) {
        cout << i << "\n";
        break;
    }

    return 0;
}