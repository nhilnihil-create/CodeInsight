#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int MAX_N = 202020;

int main() {
    int n;
    cin >> n;

    vector<int> c(MAX_N);
    rep(i, n) {
        cin >> c[i];
        c[i]--;
    }

    vector<ll> dp(MAX_N);
    vector<int> last(MAX_N, -1);

    dp[0] = 1;
    rep(i, n) {
        dp[i+1] = dp[i];
        if(last[c[i]] != -1 && last[c[i]] != i-1) {
            dp[i+1] += dp[last[c[i]] + 1];
            dp[i+1] %= mod;
        }
        last[c[i]] = i;
    }

    cout << dp[n] << endl;
    return 0;
}