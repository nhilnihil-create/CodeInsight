#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+1e3;
int h[N],dp[N];
int main(){
    int n,k; cin >> n >> k;
    for(int i = 1; i <= n; i++)cin >> h[i];
    for(int i = 0; i <= n; i++)dp[i] = 1e9;
    dp[1] = 0;
    for(int i = 2; i <= n; i++){
        for(int j = max(1,i-k); j < i; j++){
            dp[i] = min(dp[i],abs(h[j]-h[i])+dp[j]);
        }
    }
    cout << dp[n];
}
