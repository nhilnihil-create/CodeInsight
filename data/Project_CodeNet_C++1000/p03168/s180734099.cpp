#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
#include <stack>
#include <vector>
#include <random>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define oo 1e18
using namespace std;
typedef long long ull;
typedef pair<int, int> ii;
typedef pair<long double, int> id;
typedef pair<long long, long long> llp;
const int N = 3*1e3+1;
int n, m, t, k;
double dp[N][N], p[N];
// Let dp[n][K] is the probability of getting K heads with n last coins
int main() {
    //freopen("ee.inp", "r", stdin);
    //freopen("ee.OUT", "w", stdout);
    fastIO;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];

    dp[1][0] = 1-p[1], dp[1][1] = p[1];
    for(int i=2;i<=n;i++) {
        dp[i][0] = dp[i-1][0]*(1-p[i]); // calculate probability of getting 0 heads
        dp[i][i] = dp[i-1][i-1]*p[i]; // calculate probability of getting i heads with i last coins
    }
    // calculate : probability of getting j heads with i first coins
    /*
        if we choose i to be head, we have this formula : dp[i-1][j-1]*p[i]
        if we choose i to be tail, we have this formula : dp[i-1][j]*(1-p[i])
        from here we can calculate dp[i][j], just simply add 2 of the above formulas to dp[i][j]
    */
    for(int i=2;i<=n;i++) for(int j=1;j<i;j++) dp[i][j] =   dp[i-1][j-1]*p[i] + // if we choose i to be head
                                                            dp[i-1][j]*(1-p[i]); // if we choose i to be tail
    double ans = 0;
    for(int i=n/2+1;i<=n;i++) ans+=dp[n][i];
    cout << setprecision(10) << ans;
}
