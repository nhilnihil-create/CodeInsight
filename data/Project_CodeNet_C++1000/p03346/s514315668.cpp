#include <bits/stdc++.h>
using namespace std;
int a[200002], dp[200002];
int main(){
    int n, ans = 0;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        dp[a[i]] = max(dp[a[i]], dp[a[i]-1]+1);
        ans = max(ans, dp[a[i]]);
    }   
    printf("%d\n", n-ans);
}