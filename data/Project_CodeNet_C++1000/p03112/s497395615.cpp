#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vs = vector<string>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, q;
    cin >> a >> b >> q;
    vll s(a+2), t(b+2);
    s[0] = t[0] = -1e18;
    s[a+1] = t[b+1] = 1e18; 
    rep(i, a) cin >> s[i+1];
    rep(i, b) cin >> t[i+1];

    while (q--) {
        ll x;
        cin >> x;
        ll ans = __LONG_LONG_MAX__;
        int sidx = lower_bound(s.begin(), s.end(), x) - s.begin();
        int tidx = lower_bound(t.begin(), t.end(), x) - t.begin();
        rep(i, 2) {
            rep(j, 2) {
                chmin(ans, abs(x-s[sidx-i]) + abs(s[sidx-i] - t[tidx-j]));
                chmin(ans, abs(x-t[tidx-j]) + abs(s[sidx-i] - t[tidx-j]));
            }
        } 
        cout << ans << endl;
    }
}