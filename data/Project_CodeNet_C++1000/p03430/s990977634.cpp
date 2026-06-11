#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
string S;
int dp[305][305][305];
int K;

int main() {
    //cout.precision(10);
    cin >> S;
    cin >> K;
    int n = S.size();
    S = "#" + S;
    int ans = 0;
    for(int k = 0; k <= K; k++) {
        for(int i = 0; i <= n; i++) {
            for(int j = n + 1; j >= max(1, i); j--) {
                ans = max(ans, dp[i][j][k]);
                //cerr << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
                dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
                dp[i][j-1][k] = max(dp[i][j-1][k], dp[i][j][k]);
                if(S[i+1] == S[j-1]) {
                    if(i+1 == j-1) dp[i+1][j-1][k] = max(dp[i+1][j-1][k], dp[i][j][k]+1);
                    else dp[i+1][j-1][k] = max(dp[i+1][j-1][k], dp[i][j][k] + 2);
                }
                if(i+1 == j-1) dp[i+1][j-1][k+1] = max(dp[i+1][j-1][k+1], dp[i][j][k] + 1);
                else dp[i+1][j-1][k+1] = max(dp[i+1][j-1][k+1], dp[i][j][k] + 2);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
