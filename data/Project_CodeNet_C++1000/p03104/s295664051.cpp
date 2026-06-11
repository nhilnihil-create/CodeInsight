/**
*    created: 24.07.2020 15:26:12
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
const int MAX = 1000010;
const int INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int a, b; cin >> a >> b;
    vector<int> f, l;
    if (b - a <= 4) {
        int ans = 0;
        rep2(i,a,b+1) ans ^= i;
        cout << ans << endl;
        return 0;
    }
    while (a % 4 != 0) {
        f.push_back(a);
        a++;
    }
    while (b % 4 != 3) {
        l.push_back(b);
        b--;
    }
    int ans = 0;
    if (f.size() != 0) for (auto p : f) ans ^= p;
    if (l.size() != 0) for (auto p : l) ans ^= p;
    cout << ans << endl;
    return 0;
}