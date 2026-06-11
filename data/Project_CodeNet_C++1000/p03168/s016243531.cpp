#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<double> p(n);
    for(int i=0;i<n;i++)    cin>>p[i];
    vector<vector<double>> dp(n+1, vector<double> (n+1,0));
    dp[0][0]=1.0;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=i;j++) {
            if(j==0) 
                dp[i][j] = dp[i-1][j]*(1-p[i-1]);
            else 
                dp[i][j] = dp[i-1][j]*(1-p[i-1]) + dp[i-1][j-1]*p[i-1];
        }
    }
    double res=0.0;
    for(int i=n/2+1;i<=n;i++)    
        res += dp[n][i];
    printf("%0.10lf",res);
}
