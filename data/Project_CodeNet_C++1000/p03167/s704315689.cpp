#include<iostream>
#include<vector>
#define ll long long int

ll mod = 1e9 +7;

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(1001, vector<int>(1001));
    vector<vector<ll>> dp(1001, vector<ll>(1001));
    char ch = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> ch;
            if(ch=='.') arr[i][j]=1;
            else arr[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!arr[i][j]) dp[i][j]=0;
            else if(i==1 && j==1) dp[i][j]=1;
            else if(i-1>0 && j-1>0){
                dp[i][j] = ( dp[i-1][j] + dp[i][j-1] )%mod; 
            }
            else if(i-1>0){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}