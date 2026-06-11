#include <bits/stdc++.h>
using namespace std;

int main(){
    int h , w;
    cin >> h >> w;
    const int INF = 1e4;
    vector<vector<int>> dp(10, vector<int>(10, INF));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> dp[i][j];
        }
    }

    for(int i = 0; i < 10; i++) dp[i][i] = 0;
    for(int k = 0; k < 10; k++){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int a;
            cin >> a;
            if(a != -1){
                ans += dp[a][1];
            }
        }
    }

    cout << ans << endl;
}