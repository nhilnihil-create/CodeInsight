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

#define int long long

signed main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(n);
    rep(i, n) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    int money = 0;
    int sum = 0;
    int i = 0;
    while (true) {
        if (sum + v[i].second <= m) {
            money += v[i].first * v[i].second;
            sum += v[i].second;
        }
        else {
            money += (m - sum) * v[i].first;
            sum = m;
        }
        if (sum == m)
            break;
        i++;
    }
    cout << money << endl;
    return 0;
}