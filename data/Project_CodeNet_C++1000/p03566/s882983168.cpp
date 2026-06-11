#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);

    int n;
    cin >> n;
    vector<int> T(n);
    vector<int> V(n);

    for (int i = 0; i < n; ++i) {
        cin >> T[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
    }
    
    const long long INF = 1LL << 60;
    auto calc = [&](int v0, int v1, int mx, int t) -> long double {
        long double res = 0;
        if (v0 > mx || v1 > mx) {
            return -INF;
        }
        if (t < abs(v1 - v0)) {
            return -INF;
        }

        int t0 = (mx - v0);
        int t1 = (mx - v1);
        
        if (t0 + t1 > t) {
            if (v1 > v0) {
                swap(v1, v0);
            }
            long double t1 = v0 - v1;
            long double t0 = (t - t1) / 2;
            t1 += t0;
            long double v = v0 + t0;
            res += (v + v0) / 2.0 * t0;
            res += (v + v1) / 2.0 * t1;
            // cout << v << " : " << t0 << " " << t1 << endl;
        } else {
            res += (v0 + mx) / 2.0 * t0;
            res += (v1 + mx) / 2.0 * t1;
            res += (t - t1 - t0) * 1.0 * mx;
        }
        return res;
    };
    long long res = 0;

    int M = 0;
    for (auto x : V) {
        M = max(M, x);
    }

    vector<long double> dp(M + 1, -INF);
    dp[0] = 0;
    auto ndp = dp;

    for (int i = 0; i < n; ++i) {
        fill(begin(ndp), end(ndp), -INF);
        for (int j = 0; j <= M; ++j) {
            if (dp[j] < 0) {
                continue;
            }
            for (int k = 0; k <= V[i]; ++k) {
                auto mx = calc(j, k, V[i], T[i]);
                ndp[k] = max(ndp[k], dp[j] + mx);
            }
        }
        swap(ndp, dp);
    }
    
    cout << dp[0] << '\n';

    return 0;
}