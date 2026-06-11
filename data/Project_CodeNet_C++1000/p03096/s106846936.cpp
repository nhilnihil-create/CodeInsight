#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <random>
#include <complex>
#include <random>
#include <functional>
 
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> dp(n);
    dp[0] = 1;
    vector<int> c(n);
    for (auto &t : c) {
    	cin >> t;
    }
    map<int, int> pr;
    pr[c[0]] = 0;
    for (int i = 1; i < n; i++) {
    	dp[i] += dp[i - 1];
    	if (pr.count(c[i]) && pr[c[i]] < i - 1) {
    		dp[i] += dp[pr[c[i]]];
    		dp[i] %= MOD;
    	}
    	pr[c[i]] = i;
    }
    cout << dp[n - 1] << endl;
}
