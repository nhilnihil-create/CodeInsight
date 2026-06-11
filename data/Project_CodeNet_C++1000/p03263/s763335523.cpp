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
    
    int h, w;
    cin >> h >> w;
    vvi a(h, vi(w));
    rep(i, h) rep(j, w) {
        cin >> a[i][j];
        a[i][j] %= 2;
    }
    vector<pair<P, P>> ans;
    rep(i, h) {
        rep(j, w) {
            if (i == h-1 && j == w-1) break;
            if (j == w-1 && a[i][j] == 1) {
                ans.eb(P(i+1, j+1), P(i+2, j+1));
                a[i][j] = 0;
                a[i+1][j] = 1 - a[i+1][j];
                break;
            }
            if (a[i][j] == 1) {
                ans.eb(P(i+1, j+1), P(i+1, j+2));
                a[i][j] = 0;
                a[i][j+1] = 1 - a[i][j+1];
            }
        }
    }
    cout << sz(ans) << endl;
    rep(i, sz(ans)) printf("%d %d %d %d\n", ans[i].fi.fi, ans[i].fi.se, ans[i].se.fi, ans[i].se.se);
}