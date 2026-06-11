#include <bits/stdc++.h>
using namespace std;

int N; long long A, B;

int p[5005];
int rev[5005];

// Second indx:
/*
1: (-inf, 1]
2: (1, 2]
3: (2, 3]
4: (3, 4] and so on.
N+1: (N, N+1]
*/
//long long memo[5005][5005];
long long dp[5005][5005];

// Sort from 1 to i inclusive
// The element i+1 is in k
/*long long dp(int i, int k){
    if(i == 0){
        return 0;
    }else if(memo[i][k] != -1){
        return memo[i][k];
    }else{
        // shift left
        long long ans = 1LL << 61;

        for(int j = 1; j <= k; j ++){
            if(j < rev[i]){
                ans = min(ans, B + dp(i-1, j));
            }else if(j == rev[i]){
                ans = min(ans, B*(j==k) + dp(i-1, j));
            }else{
                ans = min(ans, A + dp(i-1, j));
            }
        }

        //printf("dp(%d, %d)=%lld\n", i, k, ans);
        return memo[i][k] = ans;
    }
}*/

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
                ans = min(ans, B + dp[i-1][j]);
            }else if(j == rev[i]){
                ans = min(ans, dp[i-1][j]);
            }else{
                ans = min(ans, A + dp[i-1][j]);
            }

            dp[i][j] = ans;
            if(j == rev[i]){
                dp[i][j] = min(ans, dp[i-1][j]);
            }
        }
    }

    printf("%lld", dp[N][N+1]);
    return 0;
}
