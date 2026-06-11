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

    string s;
    cin >> s;
    int n = s.length();

    const long long MOD = 1000000007;

    long long res = 0;
    vector<long long> dp(5, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {

        if (s[i] != '?') {
            int x = s[i] == 'A' ? 1 : s[i] == 'B' ? 2 : 3;
            for (int j = 2; j >= 0; --j) {
                if (x == j + 1) {
                    (dp[x] += dp[j]) %= MOD;
                }
            }
        } else {
            for (int j = 3; j >= 0; --j) {
                (dp[j + 1] += dp[j]) %= MOD; 
                (dp[j] *= 3) %= MOD;
            }
        }
    }

    cout << dp[3] << '\n';

    return 0;
}