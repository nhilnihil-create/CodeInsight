/**
*    created: 03.07.2020 02:40:22
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

int l[10000];


signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    
    int n;
    cin >> n;

    l[0] = 2;
    l[1] = 1;
    rep2(i,2,100) {
        l[i] = l[i-1] + l[i-2];
    } 
    cout << l[n] << endl;
    return 0;
}