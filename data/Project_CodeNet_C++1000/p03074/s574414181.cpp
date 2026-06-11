#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
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
    string s;
    cin >> s;
    vector<P> vp;
    vp.eb(s[0] - '0', 0);
    rep(i, n) {
        if (vp.back().fi == s[i] - '0') {
            vp.back().se++;
        } else {
            vp.eb(s[i] - '0', 1);
        }
    }
    int m = sz(vp);
    int r = 0;
    int now = 0;
    int sm = 0;
    int ans = 0;
    for (int l = 0; l < m; ++l) {
        while (now + (vp[r].fi == 0) <= k && r < m) {
            now += (vp[r].fi == 0);
            sm += vp[r].se;
            r++;
        }
        chmax(ans, sm);
        sm -= vp[l].se;
        now -= (vp[l].fi == 0);
    }
    cout << ans << endl;
}