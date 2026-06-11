#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> six(7);
    vector<int> nine(6);
    six[0] = 1;
    for (int i=1;i<7;i++){
        six[i] = six[i-1]*6;
    }
    nine[0] = 1;
    for (int i=1;i<6;i++){
        nine[i] = nine[i-1]*9;
    }
    vector<int> dp(N+1,INF);//i円以上になるときの回数の最小値
    dp[0] = 0;
    for (int i=0;i<N;i++){
        dp[i+1] = min(dp[i+1],dp[i]+1);
        for (int j=0;j<7;j++){
            if (i+six[j] <=N){
                dp[i+six[j]] = min(dp[i+six[j]], dp[i] + 1);
            }
        }
        for (int j=0;j<6;j++){
            if (i+nine[j]<=N){
                dp[i+nine[j]] = min(dp[i+nine[j]], dp[i] + 1);
            }
        }
    }
    int ans = INF;
    for (int i=0;i<=N;i++){
        ans = min(ans, dp[i] + N - i);
    }
    cout << ans << endl;
}