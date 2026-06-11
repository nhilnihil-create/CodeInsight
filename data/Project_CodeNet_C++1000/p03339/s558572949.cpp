/**
*    created: 30.06.2020 14:37:10
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

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> e(n);
    vector<int> w(n);
    rep(i,n) {
        if (s[i] == 'E') e[i]++;
        else w[i]++;
    }
    rep(i,n) {
        if (i == 0) continue;
        e[i] += e[i-1];
        w[i] += w[i-1];
    }
    int ans = inf;
    rep(i,n) {
        if (i == 0) chmin(ans,e[n-1]-e[i]);
        else chmin(ans,e[n-1]-e[i]+w[i-1]);
    }
    cout << ans << endl;
    return 0;
}