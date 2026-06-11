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

    vector<int> cnts(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int x = i;
        for (int i = 2; i * i <= x; ++i) {
            int cnt = 0;
            while (x % i == 0) {
                ++cnt;
                x /= i;
            }
            cnts[i] += cnt;
        }
        if (x > 1) {
            cnts[x] += 1;
        }
    }


    const int M = 75;
    vector<long long> dp(M + 1, 0);
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        // cout << i << " " << cnts[i] << endl;
        int m = cnts[i];
        for (int j = M; j > 0; --j) {
            for (int k = 1; k <= m; ++k) {
                long long nj = j * 1LL * (k + 1);
                if (nj > M) {
                    break;
                }
                dp[nj] += dp[j];
            }
        }
    }

    cout << dp[M] << '\n';

    return 0;
}