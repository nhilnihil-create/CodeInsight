/**
*    created: 30.06.2020 17:07:11
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pcnt(bit) __builtin_popcountll(bit)
using namespace std;
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
const int mod = 1000000007;
const long double pi = acos(-1.0);
const int inf = 1LL << 60;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    int mp[h+2][w+2];
    rep(i,h+2) rep(j,w+2) mp[i][j] = 0;
    string s;
    rep2(i,1,h+1) {
        cin >> s;
        rep2(j,1,w+1) if (s[j-1] == '#') mp[i][j] = 1;
    }
    rep2(i,1,h+1) rep2(j,1,w+1) if (mp[i][j] == 1) {
        if (mp[i+1][j] == 0 && mp[i-1][j] == 0 && mp[i][j+1] == 0 && mp[i][j-1] == 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}