#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define itn int
#define rep(i,n) for(int i = 0;i < n;i++)
#define P pair<int,int>

long long dp[200000][4];

int main(void){
    int n;
    cin >> n;
    
    long long a[n];
    for(int i = 0;i < n;i++)cin >> a[i];
    
    dp[2][0] = a[0]+a[1],dp[2][1] = -a[0]-a[1];
    for(int i = 2;i < n;i++){
        dp[i+1][0] = max(dp[i][0],dp[i][1])+a[i];
        dp[i+1][1] = max(dp[i][0]-a[i-1]-a[i-1]-a[i],dp[i][1]+a[i-1]+a[i-1]-a[i]);
    }
    cout << max(dp[n][0],dp[n][1]) << endl;
}