#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> b;
    rep(i, n) {
        ll tmp = a[i];
        b.push_back(tmp);
        FOR(j, i+1, n) {
            tmp += a[j];
            b.push_back(tmp);
        }
    }
    sort(b.rbegin(), b.rend());
    vector<vector<int>> c(sz(b), vector<int>(41, 0));
    int loc = 0;
    for(const auto& num : b) {
        for(int i=40; i>=0; i--) {
            if (1ll<<i & num) c[loc][i]++;
            // debug(num, loc, i);
        }
        loc++;
    }
    print(c);
    ll ans = 0;
    bool found = false;
    set<int> st;
    for(int i=40; i>=0; i--) {
        if (!found) {
            st.clear();
            rep(j, sz(c)) {
                if (c[j][i]) st.insert(j);
            }
            if (sz(st)>=k) {
                found = true;
                ans += 1ll<<i;
            }
        } else {
            set<int> st2;
            for(const auto& s: st) {
                if (c[s][i]) st2.insert(s);
            }
            if (sz(st2)>=k) {
                st = st2;
                ans += 1ll<<i;
            }
        }
    }
    cout << ans << endl;
}