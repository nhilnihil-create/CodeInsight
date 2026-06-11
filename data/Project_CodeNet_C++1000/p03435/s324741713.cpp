/**
*    created: 01.07.2020 21:55:21
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

    int a1 = 0;
    int a2, a3, b1, b2, b3;
    cin >> b1 >> b2 >> b3;
    int tmp1, tmp2, tmp3, tmp4, tmp5, tmp6;
    cin >> tmp1 >> tmp2 >> tmp3 >> tmp4 >> tmp5 >> tmp6;
    a2 = tmp1 - b1;
    a3 = tmp4 - b1;
    if (a2 + b2 != tmp2) {cout << "No" << endl; return 0;}
    if (a2 + b3 != tmp3) {cout << "No" << endl; return 0;}
    if (a3 + b2 != tmp5) {cout << "No" << endl; return 0;}
    if (a3 + b3 != tmp6) {cout << "No" << endl; return 0;}
    cout << "Yes" << endl;
    return 0;
}