#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define F first
#define S second
#define mod 1000000007
#define pb push_back
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REV(i,a,n) for(int i=a;i>=n;i--)
#define all(a) a.begin(),a.end()
#define UB upper_bound
#define LB lower_bound
const int NUM = 2e5 + 5;
int dp[100][NUM];
// dp[x][y]  = no of ways of distributing y candies till position x
/* bases Cases
    dp[x][0] = 1 // at any position not giving candy to someone
    dp[0][y] = 1
    dp[x][y] = dp[x-1][y] + dp[x-1][y-1] + dp[x-1][y-2] + .. + dp[x-1][y-a[x]] 
*/
int a[100],n,k;
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int num_tests=1; 
    //cin >> num_tests;
    while(num_tests-->0){
        cin >> n >> k;
        FOR(i,0,n){
            cin >> a[i];
        }
        FOR(i,0,a[0]+1)
            dp[0][i] = 1;
        FOR(i,1,n){
            vector<int> ps(k+1,0);
            ps[0] = dp[i-1][0];
            FOR(j,1,k+1)
                ps[j] = (ps[j-1] + dp[i-1][j]) % mod;
            FOR(j,0,k+1){
                if(j > a[i])
                    dp[i][j] = (ps[j] - ps[j-a[i]-1] + mod) % mod;
                else 
                    dp[i][j] = ps[j];
            }
        }
        cout << dp[n-1][k];
    }   
}