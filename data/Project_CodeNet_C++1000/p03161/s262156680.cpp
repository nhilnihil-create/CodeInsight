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

int jumps(int N, int a[],int k) {
    int x,y;
    int dp[N+1] = {0}; 
    for(int i=2; i<=N; i++) {
        x = y = INT_MAX;
        for(int j=1; j<=k; j++) {
            if(i-j>=1) x = dp[i-j] + abs(a[i] - a[i-j]);
            y = min(x,y); 
        }
        dp[i] = y;
    }
    return dp[N];
}

int main() {
    int N,k;
    cin>>N>>k;
    int a[N+1]; 
    for(int i=1; i<=N; i++) cin>>a[i];
    cout<<jumps(N,a,k);
    return 0;
}