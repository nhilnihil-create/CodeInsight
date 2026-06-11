/**
*    created: 28.06.2020 02:10:44
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

    int n, k;
    cin >> n >> k;
    int i = 0;
    while (true) {
        if (k * i >= n + i - 1) break;
        i++;
    }
    cout << i << endl;
    return 0;
}