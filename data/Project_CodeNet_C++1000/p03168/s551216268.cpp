#include <bits/stdc++.h>
using namespace std;
#define ll long long


double dp[3000][3000];


double coins(int n, vector<double>& p){
    /*
    if(i < k || k < 0) return 0;
    if(i==1 && k==1) return p[0];
    if(i==1 && k==0) return(1-p[0]);
    
    if(dp[i][k] != 0) return dp[i][k];
    
    
    return dp[i][k] = (p[i-1]*coins(i-1,k-1,p) + (1-p[i-1])*coins(i-1,k,p));
    */
     
    double dp[n+1][n+1] = {};
    dp[1][0] = 1-p[0];
    dp[1][1] = p[0];
    
    for(int i = 2;i <= n; i++){
        dp[i][0] = (1-p[i-1])*dp[i-1][0];
        for(int j = 1; j <= i; j++){
            dp[i][j] = p[i-1]*dp[i-1][j-1] + (1-p[i-1])*dp[i-1][j];
        }
    }
    
    double sum = 0;
    for(int i = n/2 + 1 ; i <=n; i++) sum += dp[n][i];
    
    return sum;
}




int main(){
    int n; cin >> n;
    vector<double> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    
    /*
    double sum = 0;
    for(int j = n/2 + 1; j <= n; j++) sum += coins(n,j,p);
    cout << fixed << setprecision(10) << sum  << endl;
    */

    cout << fixed << setprecision(10) << coins(n,p);
    return 0;
}