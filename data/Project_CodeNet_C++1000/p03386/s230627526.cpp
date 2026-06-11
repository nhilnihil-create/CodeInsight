/**
*    created: 01.07.2020 13:59:46
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

    int a, b;
    cin >> a >> b;
    int k;
    cin >> k;
    if (2*k >= b-a+1) {
        rep2(i,a,b+1) cout << i << endl;
        return 0;
    }
    else {
        rep2(i,a,a+k) cout << i << endl;
        rep2(i,b-k+1,b+1) cout << i << endl;
        return 0;
    }
}