#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    int A[2][n];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<n;j++)
            cin>>A[i][j];
    }
    int dp[2][105];
    dp[0][0] = A[0][0];
    dp[1][0] = A[0][0] + A[1][0];
    for(int j = 1; j < n; j++)
        dp[0][j] = dp[0][j-1] + A[0][j]; 
    for(int j = 1; j < n; j++)
    {
        dp[1][j] = max(dp[0][j], dp[1][j-1]) + A[1][j];
    }
    cout << dp[1][n-1] << endl;
    return 0 ; 
}