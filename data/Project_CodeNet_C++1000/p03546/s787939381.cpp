
#include <iostream>
#include <iomanip> //! for setprecision(10)
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>

using namespace std;

typedef long long LL;

#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 
#define rep(i,n) for (int i = 0; i < (n); ++i)

const int MOD = 1000000007;

int dp[10][10];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

    int h, w;
    cin >> h >> w;

    rep(i, 10) rep(j, 10) {
        cin >> dp[i][j];
    }

    rep(k, 10) rep(i, 10) rep(j, 10)
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    
    int ans = 0;
    rep(i, h*w) {
        int a;
        cin >> a;
        if (0 <= a) {
            ans += dp[a][1];
        }
    }
    cout << ans << endl;

    return 0;
}
