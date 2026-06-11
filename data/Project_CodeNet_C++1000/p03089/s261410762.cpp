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
#define INF 1e18
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
    vector<int> r;
    rep(i, n) {
        int ext = -1;
        for (int j = a.size() - 1; j >= 0; j--) {
            if (a[j] == j + 1) {
                ext = j;
                break;
            }
        }
        if (ext == -1) {
            cout << -1 << endl;
            return 0;
        }
        a.erase(a.begin() + ext);
        r.push_back(ext + 1);
    }
    reverse(r.begin(), r.end());
    for (auto q : r) {
        cout << q << endl;
    }
    return 0;
}