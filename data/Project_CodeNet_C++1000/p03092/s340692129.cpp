#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 5005;
ll A, B, N, arr[MN], dp[MN][MN], i, j;
ll solve(ll n,ll lim){
    if(n==0) return 0;
    else if(dp[n][lim]!=-1) return dp[n][lim];
    if(arr[n]>lim) dp[n][lim]=A+solve(n-1,lim);
    else dp[n][lim]=min(solve(n-1,arr[n]),solve(n-1,lim)+B);
    return dp[n][lim];
}
int main(){
    for(scanf("%lld%lld%lld",&N,&A,&B),i=1;i<=N;i++)
        scanf("%lld",&arr[i]);
    memset(dp,-1,sizeof(dp));
    printf("%lld\n",solve(N,N+1));
    return 0;
}
