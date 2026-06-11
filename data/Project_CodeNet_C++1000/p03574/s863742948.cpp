/**
*    created: 03.07.2020 17:04:59
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
const long double pi = acos(-1.0);
const int INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    char mp[h][w];
    int ans[h][w];
    rep(i,h) rep(j,w) ans[i][j] = 0;
    rep(i,h) rep(j,w) cin >> mp[i][j];
    rep(i,h) rep(j,w) {
        if (mp[i][j] == '#') {
            ans[i][j] = -INF;
            if (0 <= j+1 && j+1 < w) ans[i][j+1]++;
            if (0 <= j-1 && j-1 < w) ans[i][j-1]++;
            if (0 <= i+1 && i+1 < h) ans[i+1][j]++;
            if (0 <= j-1 && j-1 < w && 0 <= i+1 && i+1 < h) ans[i+1][j-1]++;
            if (0 <= j+1 && j+1 < w && 0 <= i+1 && i+1 < h) ans[i+1][j+1]++;
            if (0 <= i-1 && i-1 < h) ans[i-1][j]++;
            if (0 <= j+1 && j+1 < w && 0 <= i-1 && i-1 < h) ans[i-1][j+1]++;
            if (0 <= j-1 && j-1 < w && 0 <= i-1 && i-1 < h) ans[i-1][j-1]++;
        }
    }
    rep(i,h) {
        rep(j,w) {
            if (ans[i][j] < 0) cout << '#';
            else cout << to_string(ans[i][j]);
        }
        cout << endl;
    }
    return 0;
}