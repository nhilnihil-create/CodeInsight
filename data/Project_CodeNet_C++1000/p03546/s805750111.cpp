#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int h, w;
    cin >> h >> w;
    vector<vector<int>> c(10, vector<int>(10));
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin >> c[i][j];
        }
    }

    // 各 1 <= i <= 9 から 0 への最短路
    // WF
    int INF = (1<<29);
    vector<vector<int>> dp = c;
    for(int i=0; i<10; i++){
        dp[i][i] = 0;
    }
    for(int k=0; k<10; k++){
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
            }
        }
    }

    int ans = 0;
    for(int i=0; i<h; i++){
        for(int i=0; i<w; i++){
            int a;
            cin >> a;
            if(a != -1){
                ans += dp[a][1];
            }
        }
    }
    cout << ans << endl;
    return 0;
}