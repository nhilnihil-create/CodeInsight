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

    if(n == 3) {
        cout << "2 5 63\n";
        return 0;
    }
    if(n == 4) {
        cout << "2 5 20 63\n";
        return 0;
    }

    vector<ll> v00;
    for(ll i=2; i<29990; i+=6) v00.push_back(i);
    for(ll i=4; i<29992; i+=6) v00.push_back(i);
    v00.push_back(29990);
    v00.push_back(29992);
    v00.push_back(6);
    v00.push_back(29996);
    v00.push_back(29998);
    v00.push_back(12);
    vector<ll> v0, v3;
    REP(i, 7500) v0.push_back(v00[i]);
    FOR(i, 7500, 10002) v3.push_back(v00[i]);
    vector<ll> v1;
    for(ll i=3; i<30000; i+=6) v1.push_back(i);
    vector<ll> v2;
    for(ll i=18; i<=30000; i+=6) v2.push_back(i);

    dump(v0.size());
    dump(v1.size());
    dump(v2.size());
    dump(v3.size());

    REP(i, 20) cerr << v0[i] << " ";
    cerr << endl;
    REP(i, 20) cerr << v1[i] << " ";
    cerr << endl;
    REP(i, 20) cerr << v2[i] << " ";
    cerr << endl;
    REP(i, 20) cerr << v3[i] << " ";
    cerr << endl;

    vector<ll> ans;
    ll idx0 = 0, idx1 = 0;
    ll lim = min(2500LL, n/5);
    REP(i, lim) {
        ans.push_back(v0[idx0++]);
        ans.push_back(v0[idx0++]);
        ans.push_back(v0[idx0++]);
        ans.push_back(v1[idx1++]);
        ans.push_back(v1[idx1++]);
    }
    n -= lim*5;

    ll idx3 = 0;
    lim = min(834LL, n/3);
    dump(n, lim);
    REP(i, lim) {
        ans.push_back(v3[idx3++]);
        ans.push_back(v3[idx3++]);
        ans.push_back(v3[idx3++]);
    }
    n -= lim*3;

    ll idx2 = 0;
    dump(n);
    REP(i, n) ans.push_back(v2[idx2++]);

    REP(i, ans.size()) cout << ans[i] << (i+1==ans.size() ? '\n' : ' ');

    return 0;
}