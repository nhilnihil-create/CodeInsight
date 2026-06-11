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

int jumps(int N, int a[]) {
    int x,y;
    int dp[N+1] = {0};
    dp[1] = 0;
    x = y = INT_MAX;
    for(int i=2; i<=N; i++) {
        if(i-1 >=1) x = dp[i-1] + abs(a[i] - a[i-1]);
        if(i-2 >=1) y = dp[i-2] + abs(a[i] - a[i-2]);
        dp[i] = min(x,y);
    }
    return dp[N];
}

int main() {
    int N;
    cin>>N;
    int a[N+1]; 
    for(int i=1; i<=N; i++) cin>>a[i];
    cout<<jumps(N,a);
    return 0;
}