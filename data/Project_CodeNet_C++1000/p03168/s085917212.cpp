#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int maxN = 3e3+5;
const int mod = 1e9+7;
double P[maxN],dp[maxN][maxN];
int n;

void solve(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>P[i];
    dp[0][0] = (1-P[0]);
    dp[0][1] = P[0];
    for(int i=1;i<n;i++){
        dp[i][0] = (1-P[i])*dp[i-1][0];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=i+1;j++){
            dp[i][j] = P[i]*dp[i-1][j-1]+(1-P[i])*dp[i-1][j];
        }
    }
    double ans = 0;
    for(int i=n/2+1;i<=n;i++){
        ans += dp[n-1][i];
    }
    cout<<setprecision(11)<<ans<<endl;
}

int main()
{
    FASTIO
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}




