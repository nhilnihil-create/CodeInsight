#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
const int mxN=1e9;
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n;
    cin>>n;

    vector<double> v(n);

    for(int i=0;i<n;i++)cin>>v[i];

    double dp[n+1][n+1];
    memset(dp,0,sizeof(dp));

    dp[0][0]=1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            dp[i][j] = dp[i-1][j]*(1-v[i-1]);
            if(j>0) dp[i][j] += dp[i-1][j-1]*v[i-1];
        }
    }

    double ans = 0;
    for(int i=n/2+1;i<=n;i++) ans+=dp[n][i];

    cout<<setprecision(10)<<ans;
}