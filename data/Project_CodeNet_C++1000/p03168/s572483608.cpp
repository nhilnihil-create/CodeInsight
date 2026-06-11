#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
using namespace std;

int solution(){
    int n; cin>>n;
    vector<double> p(n);
    cout<<fixed;
    cout<<setprecision(10);
    for(int i = 0;i < n;i++) cin>>p[i];
    
    vector<vector<double> > dp(n+1, vector<double> (n+1, 0.0) );
    dp[0][0] = 1;
    for(int i = 1;i < n+1;i++) dp[i][0] = dp[i-1][0] * (1-p[i-1]);
    
    for(int i = 1; i < n+1;i++){
        for(int j = 1; j <= i;j++){
                dp[i][j] = dp[i-1][j] * (1-p[i-1]) + dp[i-1][j-1] * (p[i-1]);
        }
    }
    double sum = 0.0;
    for(int i = n;i > n/2;i--) sum += dp[n][i];
    cout<<sum<<"\n";
    return 0;
}

int main(){
    FAST_IO;
    int T = 1; //cin>>T;
    while(T--)
        solution();
    return 0;
}