#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; long long MOD=1000000007;
    scanf("%d",&n);
    int arr[n+5];
    for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
    int prev[n+5];
    int pos[200005]; memset(pos,0,sizeof(pos));
    for(int i=1;i<=n;i++){
        prev[i]=pos[arr[i]];
        pos[arr[i]]=i;
    }
    long long dp[n+5];
    dp[0]=1;
    for(int i=1;i<=n;i++){
        if(prev[i]==i-1){
            dp[i]=dp[i-1];
            continue;
        }
        if(prev[i]==0)dp[i]=dp[i-1];
        else dp[i]=dp[prev[i]]+dp[i-1];
        dp[i]%=MOD;
        //printf("%lld %lld\n",dp[i],pref[i]);
    }
    printf("%lld",dp[n]);
}
