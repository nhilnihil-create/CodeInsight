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

class Solution {
public:

};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> A(m);
    for (int i = 0; i < m; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<int> costs{0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    vector<pair<int,int>> dp(n + 1, make_pair(-1, -1));
    dp[0] = make_pair(0, 0);    

    for (int i = 1; i <= n; ++i) {
        for (int j = m - 1; j >= 0; --j) {
            int ct = costs[A[j]];
            if (i >= ct && dp[i - ct].first >= 0) {
                dp[i] = max(dp[i], make_pair(dp[i - ct].first + 1, A[j]));
            }
        }
    }

    string res;
    int cur = n;
    while (cur > 0) {
        int x = dp[cur].second;
        res += (char)('0' + x);
        cur -= costs[x];
    }
    cout << res << '\n';

    return 0;
}