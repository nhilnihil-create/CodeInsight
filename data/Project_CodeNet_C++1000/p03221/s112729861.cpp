#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
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
#define INF INT32_MAX / 2
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
//#define int long long

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> prefecture(n + 1, vector<pair<int, int>>(0));
    vector<pair<int, int>> res(m + 1);
    int p, y;
    rep(i, m) {
        cin >> p >> y;
        prefecture[p].push_back(make_pair(y, i + 1));
    }
    repk(i, 1, n + 1) sort(prefecture[i].begin(), prefecture[i].end());
    repk(i, 1, n + 1) {
        for (int j = 0; j < prefecture[i].size(); j++) {
            res[prefecture[i][j].second] = make_pair(i, j + 1);
        }
    }
    repk(i, 1, m + 1) {
        cout << setfill('0') << right << setw(6) << res[i].first;
        cout << setfill('0') << right << setw(6) << res[i].second << endl;
    }
}