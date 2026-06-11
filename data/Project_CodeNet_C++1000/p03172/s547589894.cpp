#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,k;
ll arr[100005];
ll dp[101][100005];
ll dp2[101][100005];
const ll MOD=1000000007;

int main() {
    cin >> n >> k;
    for (int i=1;i<=n;i++) {cin >> arr[i];}

    for (int j=0;j<=k;j++) {dp2[0][j]=1;}
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=k;j++) {
            if (j<=arr[i]) {dp[i][j]=dp2[i-1][j];}
            else {dp[i][j]=dp2[i-1][j]-dp2[i-1][j-arr[i]-1];}
            dp[i][j]=(dp[i][j]+MOD)%MOD;
            if (j>0) {dp2[i][j]=dp2[i][j-1]+dp[i][j];}
            else {dp2[i][j]=dp[i][j];}
            dp2[i][j]=(dp2[i][j]+MOD)%MOD;
        }
    }
    cout << dp[n][k] << endl;

}
