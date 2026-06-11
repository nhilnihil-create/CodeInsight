#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    vll b;
    rep(i, n) {
        ll sm = 0;
        for (int j = i; j < n; ++j) {
            sm += a[j];
            b.pb(sm);
        }
    }
    ll ans = 0;
    for (int i = 40; i >= 0; --i) {
        int cnt = 0;
        rep(j, sz(b)) {
            if (((ans | 1LL<<i) & b[j]) == (ans | 1LL<<i)) cnt++;
        }
        if (cnt >= k) ans |= (1LL<<i);
    }
    cout << ans << endl;
}