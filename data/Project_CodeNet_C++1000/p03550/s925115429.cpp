#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()
#define INT_MAX_HALF (INT_MAX / 2)
#define EPS (1e-10)

using namespace std;
typedef long long ll;

int main(){

    int n, z, w;
    cin >> n >> z >> w;

    vector<int> card(n);

    rep(i, n){
        cin >> card[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for(int j = n - 1; j >= 1; j--){
        dp[n][j] = abs(card[n - 1] - card[j - 1]);
    }

    dp[n][0] = abs(card[n - 1] - z);

    for(int i = n - 1; i >= 1; i--){
        dp[i][n] = abs(card[n - 1] - card[i - 1]);
    }

    dp[0][n] = abs(card[n - 1] - w);

    for(int k = n - 1; k >= 1; k--){

        int tmpmax = 0;

        for(int j = n; j > k; j--){
            tmpmax = max(tmpmax, dp[k][j]);
        }

        for(int j = k - 1; j >= 0; j--){
            dp[k][j] = tmpmax;
        }

        int tmpmin = INT_MAX;

        for(int i = n; i > k; i--){
            tmpmin = min(tmpmin, dp[i][k]);
        }

        for(int i = k - 1; i >= 0; i--){
            dp[i][k] = tmpmin;
        }
    }

    int ans = 0;

    for(int j = 1; j <= n; j++){
        ans = max(ans, dp[0][j]);
    }

    cout << ans << endl;
    return 0;
}
