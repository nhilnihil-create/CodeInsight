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
const int MAX_N = 200010;

int main() {
    int n;
    cin >> n;

    vector<int> c(MAX_N);
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    vector<ll> dp(MAX_N);  // dp[i] : 最初からi個(iは1-index)の石の場合の数
    vector<int> v(MAX_N);  // v[i] : j < i かつ c[j] = c[i] となる最大のj (存在しないときは0)
    vector<int> w(MAX_N);  // vを埋めるための補助的なvector

    for(int i = 1; i <= n; i++) {
        v[i] = w[c[i]];
        w[c[i]] = i;
    }

    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i-1];  // i個目の石に操作をしない場合の数はdp[i-1]通り
        if(v[i] != 0 && v[i] != i-1) {  // j < i かつ c[j] = c[i] となるjが存在して、c[i-1] != c[i] のとき
            dp[i] += dp[v[i]];  // i個目とv[i]個目の石に対して操作を行うときの場合の数はdp[v[i]]通り
            dp[i] %= mod;
        }
    }

    cout << dp[n] << endl;
    return 0;
}