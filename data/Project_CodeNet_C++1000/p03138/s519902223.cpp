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
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    vector<int> bits(41, 0);
    rep(i, n) {
        ll num = a[i];
        rep(j, 41) {
            if (num%2==0) bits[j]++;
            num /= 2;
        }
    }
    debug(bits);
    rep(i, 41) {
        if (bits[i]>n/2) bits[i]=1;
        else bits[i]=0;
    }
    debug(bits);
    ll tot = 0;
    for(int i=40; i>=0; i--) {
        ll num = 1ll<<i;
        if (bits[i] && tot+num>k) {
            bits[i]=0;
        } else if (bits[i]) {
            tot += num;
        }
    }
    debug(tot);
    ll ans = 0;
    rep(i, n) {
        ans += tot^a[i];
    }
    cout << ans << endl;
}
