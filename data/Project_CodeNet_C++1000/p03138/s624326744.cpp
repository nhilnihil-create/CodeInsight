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

    int n;
    cin >> n;
    long long K;
    cin >> K;
    vector<long long> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    ++K;
    long long mx = K;
    for (auto x : A) {
        mx = max(mx, x);
    }

    int h = 0;
    while (1LL << (h + 1) <= mx) {
        ++h;
    }

    vector<int> D(h + 1, 0);
    for (int i = 0; i <= h; ++i) {
        if (K & (1LL << i)) {
            D[i] = 1;
        }
    }


    const long long INF = 1LL << 62;
    vector<long long> dp(2, -INF);
    dp[0] = 0;
    auto ndp = dp;
    for (int i = h; i >= 0; --i) {
        int d = D[i];
        fill(ndp.begin(), ndp.end(), -INF);
        for (int j = 0; j < 2; ++j) {
            if (dp[j] < 0) {
                continue;
            }

            int l = 0, r = 1;
            if (j == 0) {
                r = d;
            }
            for (int x = l; x <= r; ++x) {
                int nj = j;
                if (x < d) {
                    nj = 1;
                }

                long long sum = 0;
                for (int k = 0; k < n; ++k) {
                    if (((A[k] >> i) & 1) ^ x) {
                        sum += 1LL << i;
                    }
                }

                ndp[nj] = max(ndp[nj], dp[j] + sum);
            }
        }
        swap(ndp, dp);
    }

    // cout << dp[0] << '\n';
    cout << dp[1] << '\n';


    return 0;
}