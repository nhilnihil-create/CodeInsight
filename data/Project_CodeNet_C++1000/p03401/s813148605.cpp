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

using namespace std;
//#inculude <bits/stdc++.h>
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int sum = 0;
    rep(i, n) {
        if (i == 0)
            sum += abs(a[0]);
        else if (i == n - 1)
            sum += abs(a[n - 1])+abs(a[n-1]-a[n-2]);
        else
            sum += abs(a[i] - a[i-1]);
    }
    rep(i, n) {
        int ans = sum;
        if (i == 0)
            ans = ans - abs(a[0]) - abs(a[1] - a[0]) + abs(a[1]);
        else if (i == n - 1)
            ans =
                ans - abs(a[n - 1] - a[n - 2]) - abs(a[n - 1]) + abs(a[n - 2]);
        else
            ans = ans - abs(a[i] - a[i - 1]) - abs(a[i + 1] - a[i]) +
                  abs(a[i + 1] - a[i - 1]);
        cout << ans << endl;
    }
}
