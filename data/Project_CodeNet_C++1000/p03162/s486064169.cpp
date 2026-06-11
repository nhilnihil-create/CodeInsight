#include<bits/stdc++.h>

using namespace std;

// int jumps(int n, int N, int a[],int dp[]) {
//     int x,y;
//     x = y = INT_MAX;
//     if(n == N) return 0;
//     else if(dp[n] != 0) return dp[n];
//     else {
//         if(n+1 <= N) x = jumps(n+1,N,a,dp) + abs(a[n] - a[n+1]);
//         if(n+2 <= N) y = jumps(n+2,N,a,dp) + abs(a[n] - a[n+2]);
//         dp[n] = min(x,y);
//         return dp[n];
//     }
// }

int jumps(int N, int a[][4]) {
    int x,y;
    int dp[N+1][4] = {0};
    dp[1][1] = a[1][1];
    dp[1][2] = a[1][2];
    dp[1][3] = a[1][3]; 
    if(N == 1) return max(max(dp[1][1],dp[1][2]),dp[1][3]);
    for(int i=2; i<=N; i++) {
        dp[i][1] = max(dp[i-1][2],dp[i-1][3]) + a[i][1];
        dp[i][2] = max(dp[i-1][1],dp[i-1][3]) + a[i][2];
        dp[i][3] = max(dp[i-1][2],dp[i-1][1]) + a[i][3];   
    }
    return max(max(dp[N][1],dp[N][2]),dp[N][3]);
}

int main() {
    int N;
    cin>>N;
    int a[N+1][4]; 
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=3; j++) cin>>a[i][j];  
    }
    cout<<jumps(N,a);
    return 0;
}