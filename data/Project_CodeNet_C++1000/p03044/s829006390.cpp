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
    int n, v, w, u;
    cin >> n;
    vector<vector<pair<int, int>>> tree(n, vector<pair<int, int>>(0));
    rep(i, n - 1) {
        cin >> u >> v >> w;
        tree[u - 1].emplace_back(make_pair(v - 1, w % 2));
        tree[v - 1].emplace_back(make_pair(u - 1, w % 2));
    }
    vector<bool> col(n, 0);
    vector<bool> visited(n, false);
    visited[0] = true;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (auto p : tree[t]) {
            if (visited[p.first])
                continue;
            else {
                q.push(p.first);
                visited[p.first] = true;
                if (p.second)
                    col[p.first] = !col[t];
                else
                    col[p.first] = col[t];
            }
        }
    }
    rep(i, n) cout << col[i] << endl;
}