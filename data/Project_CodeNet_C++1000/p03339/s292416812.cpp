#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repk(i, k, n) for (int i = k; i < n; i++)
#define MOD 1000000007
#define INF 1e9
#define PIE 3.14159265358979323

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T GCD(T a, T b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
template <class T>
inline T LCM(T a, T b) {
    return (a * b) / GCD(a, b);
}

signed main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> w(n + 1, 0); // wを向いている人
    vector<int> e(n + 1, 0); // eを向いている人
    rep(i, n) {
        if (s[i] == 'W') {
            w[i + 1] = w[i] + 1;
            e[i + 1] = e[i];
        }
        else {
            w[i + 1] = w[i];
            e[i + 1] = e[i] + 1;
        }
    }
    int ans = INF;
    rep(i, n) {
        chmin(ans,w[i] - w[0] + e[n] - e[i + 1]);
    }
    cout << ans << endl;
}