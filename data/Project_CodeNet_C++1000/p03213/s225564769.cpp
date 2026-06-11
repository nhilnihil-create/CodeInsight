#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

ll combination (ll a, ll b) {
    ll ret = 1;
    ll tmp_b = b;
    while(1) {
        if (tmp_b == 0) break;
        ret *= a;
        --tmp_b;
        --a;
    }
    while(1) {
        if (b == 0) break;
        ret /= b;
        --b;
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 2; i <= n; ++i) {
        int num = i;
        for (int j = 2; j * j <= i; ++j) {
            while(1) {
                if (num % j != 0) break;
                ++mp[j];
                num /= j;
            }
        }
        if (num != 1) ++mp[num];
    }
    vector<vector<int>> dp(n+1, vector<int>(76, 0));
    dp[1][1] = 1;
    for (int i = 1; i < n; ++i) {
        for (int have = 0; have <= 75; ++have) {
            for (int take = 1; take <= mp[i] + 1; ++take) {
                if (have * take > 75) continue;
                dp[i+1][have * take] += dp[i][have];
            }
        }
    }
    cout << dp[n][75] << endl;
    return 0;
}
