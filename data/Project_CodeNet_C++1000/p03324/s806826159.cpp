/**
*    created: 28.06.2020 02:26:16
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

    int d, n;
    cin >> d >> n;
    if (d == 0) {
        if (n == 100) cout << 101 << endl;
        else cout << n << endl;
    }
    if (d == 1) {
        if (n == 100) cout << 10100 << endl;
        else cout << 100 * n << endl;
    }
    if (d == 2) {
        if (n == 100) cout << 1010000 << endl;
        else cout << 10000 * n << endl;
    }
    return 0;
}