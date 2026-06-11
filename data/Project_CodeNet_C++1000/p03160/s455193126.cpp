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
    int n; cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    rep(i,100100) dp[i] = INF;
    dp[0] = 0;
    rep(i,n) {
        dp[i+1] = min(dp[i+1], dp[i]+abs(h[i+1]-h[i]));
        dp[i+2] = min(dp[i+2], dp[i]+abs(h[i+2]-h[i]));
    }
    cout << dp[n-1] << endl;
    return 0;
}