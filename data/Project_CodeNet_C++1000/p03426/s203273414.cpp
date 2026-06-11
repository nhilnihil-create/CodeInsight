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
    int h, w, d; cin >> h >> w >> d;
    vector<vector<int>> mat(h, vector<int>(w));
    map<int, P> mp;
    rep(i, h) rep(j, w) {
        int x; cin >> x;
        mat[i][j] = x;
        mp[x] = {i, j};
    }
    vector<int> s(h*w+2, 0);
    rep(i, h*w+1) {
        if (i<=d) s[i] = 0;
        else {
            s[i] = s[i-d] + abs(mp[i].fi-mp[i-d].fi) + abs(mp[i].se-mp[i-d].se);
        }
    }
    debug(s);
    int q; cin >> q;
    rep(i, q) {
        int x, y; cin >> x >> y;
        cout << s[y] - s[x] << endl;
    }
}