#include<bits/stdc++.h>
using namespace std;
long long M = 1e9+7;
int main() {
    int n,t;
    cin >> n >> t;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
        
    vector<vector<long long int> > dp(n+1,vector<long long int>(t+1,0));
    vector<vector<long long int> > prefix(n+1,vector<long long int>(t+1,0));
    

    
    for(int i = 0; i <= n;i++)
    {
        for(int j = 0;j <= t;j++)
        {
            if(j==0){
				dp[i][j]=1;
				prefix[i][j]=1;
			}else if(i==0){
				dp[i][j]=0;
				prefix[i][j]=prefix[i][j-1];
			}else if(j>a[i-1]){
				dp[i][j]=(prefix[i-1][j]-prefix[i-1][j-a[i-1]-1])%M;
				prefix[i][j]=(prefix[i][j-1]+dp[i][j]);
			}else{
				dp[i][j]=prefix[i-1][j]%M;
				prefix[i][j]=(prefix[i][j-1]+dp[i][j]);
			}
        }
    }
    cout << dp[n][t]%M << endl;
    return 0;
}