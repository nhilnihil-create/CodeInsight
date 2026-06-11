/**
*    created: 01.07.2020 23:24:49
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
const int MOD = 1000000007;
// const int MOD = 998244353;
const long double pi = acos(-1.0);
const int INF = 1LL << 60;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> u(n);
    vector<int> d(n);
    rep(i,n) cin >> u[i];
    rep(i,n) cin >> d[i];
    rep(i,n) {
        if (i == 0) continue;
        u[i] += u[i-1];
        d[i] += d[i-1];
    }
    int ans = -1;
    rep(i,n) {
        // iで下に降りる
        if (i == 0) chmax(ans,u[0]+d[n-1]);
        else chmax(ans, u[i] + d[n-1]- d[i-1]);
    }
    cout << ans << endl;
    return 0;
}