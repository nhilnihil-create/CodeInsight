#include <bits/stdc++.h>
using namespace std;

int N; long long A, B;

int p[5005];
int rev[5005];
long long dp[2][5005];

int main(){
    scanf("%d%lld%lld", &N, &A, &B);

    for(int i = 1; i <= N; i ++){
        scanf("%d", &p[i]);
        rev[p[i]] = i;
    }

    for(int j = 1; j <= N+1; j ++){
        dp[0][j] = 0;
    }

    for(int i = 1; i <= N; i ++){
        long long ans = 1LL << 61;
        for(int j = 1; j <= N+1; j ++){
            if(j < rev[i]){
                ans = min(ans, B + dp[(i-1)&1][j]);
            }else if(j == rev[i]){
                ans = min(ans, dp[(i-1)&1][j]);
            }else{
                ans = min(ans, A + dp[(i-1)&1][j]);
            }

            dp[i&1][j] = ans;
        }
    }

    printf("%lld", dp[N&1][N+1]);
    return 0;
}
