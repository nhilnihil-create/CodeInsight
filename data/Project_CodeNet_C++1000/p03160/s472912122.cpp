#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+1e3;
int h[N],dp[N];
int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++)cin >> h[i];
    dp[0] = -1e9;
    for(int i = 2; i <= n; i++){
        if(i > 2)dp[i] = min(abs(h[i-1]-h[i]) + dp[i-1],abs(h[i-2]-h[i]) + dp[i-2]);
        else dp[i] = abs(h[i-1]-h[i]) + dp[i-1];
    }
    cout << dp[n];
}
