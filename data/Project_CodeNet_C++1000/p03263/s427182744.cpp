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
    
    int h, w;
    cin >> h >> w;
    vvi a(h, vi(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    vp from, to;
    rep(i, h) {
        rep(j, w) {
            if (a[i][j] % 2 == 1) {
                if (j != w-1) {
                    from.eb(i+1, j+1);
                    to.eb(i+1, j+2);
                    a[i][j]--;
                    a[i][j+1]++;
                } else if (i != h-1 || j != w-1) {
                    from.eb(i+1, j+1);
                    to.eb(i+2, j+1);
                    a[i][j]--;
                    a[i+1][j]++;
                }
            }
        }
    }
    int n = sz(from);
    cout << n << endl;
    rep(i, n) {
        printf("%d %d %d %d\n", from[i].fi, from[i].se, to[i].fi, to[i].se);
    }
}