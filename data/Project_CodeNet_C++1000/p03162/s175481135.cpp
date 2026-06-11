#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <cstring>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll LINF = 1001002003004005006LL;
const int INF = 1001001001;

const int mod = 1000000007;

int dp[100100][3];

int main() {
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i,n) cin >> a[i] >> b[i] >> c[i];
    rep(i,n) {
        dp[i+1][0] = max(dp[i][1]+a[i], dp[i][2]+a[i]);
        dp[i+1][1] = max(dp[i][0]+b[i], dp[i][2]+b[i]);
        dp[i+1][2] = max(dp[i][0]+c[i], dp[i][1]+c[i]);
    }
    cout << max({dp[n][0],dp[n][1],dp[n][2]}) << endl;
    return 0;
}