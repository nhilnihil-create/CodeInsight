#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dp[105][100005];
signed main(){
    int N,K;
    cin >> N >> K;
    vector<int>a(N);
    dp[0][0] = 1;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        int res = 0;
        for(int j = 0; j <= K; j++) {
            res += dp[i][j];
            if(j > a[i]) {
                res -= dp[i][j-a[i]-1];
            }
            res += mod;
            res %= mod;
            dp[i+1][j] = res;
        }
    }
    cout << dp[N][K] << endl;
}
