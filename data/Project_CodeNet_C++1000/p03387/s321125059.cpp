/**
*    created: 01.07.2020 15:32:12
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
const int mod = 1000000007;
// const int MOD = 998244353;
const long double pi = acos(-1.0);
const int inf = 1LL << 60;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    int mx, md, mn;
    mx = max({a,b,c});
    mn = min({a,b,c});
    md = a + b + c - (mx + mn);
    if ((mx*2-md-mn) % 2 == 0) {
        cout << (mx*2-md-mn)/2 << endl;
        return 0;
    }
    else {
        cout << (mx*2-md-mn+3)/2 << endl;
        return 0;
    }
}