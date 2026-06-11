#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    vector<int>h(n),dp(n,INF);
    for(int i=0; i<n; i++)cin>>h[i];
    dp[0]=0;
    for(int i=0; i<n; i++){
        for(int step=1; step<=k; step++){
            if(i+step<n){
                dp[i+step]=min(dp[i+step],dp[i]+abs(h[i]-h[i+step]));
            }
        }
    }
    cout<<dp[n-1]<<endl;

    return 0;
}