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

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> gcd_left(n + 1);
    vector<int> gcd_right(n + 1);
    gcd_left[1] = a[0];
    for (int i = 1; i < n; i++) {
        gcd_left[i + 1] = GCD(gcd_left[i], a[i]);
    }
    gcd_right[n] = a[n - 1];
    for (int i = n; i > 1; i--) {
        gcd_right[i - 1] = GCD(gcd_right[i], a[i - 2]);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1)
            res = max(gcd_right[2], res);
        else if (i == n)
            res = max(gcd_left[n - 1], res);
        else
            res = max(GCD(gcd_left[i - 1], gcd_right[i + 1]), res);
    }
    cout << res << endl;
    return 0;
}