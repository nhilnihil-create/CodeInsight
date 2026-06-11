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

    int N;
    cin >> N;
    vector<int> dp(N + 1, N + 123);

    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        for (auto x : {6, 9}) {
            int p = x;
            while (i + p <= N) {
                dp[i + p] = min(dp[i + p], dp[i] + 1);
                p *= x;
            }
        }
    }

    cout << dp[N] << '\n';

    return 0;
}