#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(){
    int n;
    cin >> n;
    vector<double> p(n);
    for(int i=0;i<n;i++) cin >> p[i];
    vector<vector<double>> dp(n+1,vector<double>(n+1,0));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            dp[i+1][j+1]+=dp[i][j]*p[i];
            dp[i+1][j]+=dp[i][j]*(1-p[i]);
        }
    }
    double sum=0;
    for(int i=0;i<=n;i++){
        if(n-1<2*i) sum+=dp[n][i];
    }
    printf("%.10lf\n",sum);

}