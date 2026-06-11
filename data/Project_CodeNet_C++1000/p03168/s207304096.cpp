#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
double dp[3000][3000];
int main(){
    cin>>n;

    double pro[n+1];
    for(int x=1;x<=n;x++)
        cin>>pro[x];

    dp[0][0] = 1;

    for(int x=1;x<=n;x++){
        for(int y = 0; y<=n;y++){
            if(y > x) break;
            if(y==0){
                dp[x][y] = (1-pro[x]) * dp[x-1][0];
                continue;
            }
            dp[x][y] = pro[x] * dp[x-1][y-1] + dp[x-1][y] * (1-pro[x]);
        }
    }
    double ans = 0;

    for(int x=(n+1)/2;x<=n;x++){
        ans += dp[n][x];
    }
    printf("%.9f", ans);
}
