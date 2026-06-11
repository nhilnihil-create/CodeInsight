#include <bits/stdc++.h>
using namespace std;

int main() {
    const int Inf = 1e9;
    int h,w;
    cin >> h >> w;
    int n=10;

    int dp[10][10];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> dp[i][j];
        }
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }

    int x;
    int ans=0;
    for(int i=0; i<h*w; i++){
        cin >> x;
        if (x>=0) ans += dp[x][1];
    }

    cout << ans << endl;
    return 0;
}