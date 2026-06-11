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

int dp[100100];

int main() {
    int n, k; cin >> n >> k;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    rep(i,n+1) dp[i] = INF;
    dp[0] = 0;
    rep(i,n) {
        for (int j = 1; j<=k; ++j) {
            dp[i+j] = min(dp[i]+abs(h[i+j]-h[i]), dp[i+j]);
        }
    }
    cout << dp[n-1] << endl; 
    return 0;
}