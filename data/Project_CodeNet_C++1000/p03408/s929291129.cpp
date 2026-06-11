/**
*    created: 01.07.2020 16:36:59
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

    int n,m;
    map<string,int> bmp, rmp;
    cin >> n;
    rep(i,n) {
        string s;
        cin >> s;
        bmp[s]++;
    }
    cin >> m;
    rep(i,m) {
        string s;
        cin >> s;
        rmp[s]++;
    }
    int ans = 0;
    for (auto p : bmp) chmax(ans,p.second-rmp[p.first]);
    cout << ans << endl;
    return 0;
}