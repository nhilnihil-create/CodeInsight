#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main(){
    int n;
    scanf("%d",&n);
    int ct[200005];
    int prev[n];
    memset(ct,-1,sizeof(ct));
    int a[n];
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
        prev[i] = ct[a[i]];
        ct[a[i]] = i;
    }
    int dp[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++){
        dp[i] = dp[i-1];
        if (prev[i] != -1 && prev[i] != i-1){
            dp[i] += dp[prev[i]];
        }
        dp[i] %= mod;
    }
    //for (int i = 0; i <= n; i++) printf("%d\n",dp[i]);
    printf("%d",dp[n-1]);
}
