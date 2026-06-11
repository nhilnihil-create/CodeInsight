#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<vector<int>> v(2,vector<int> (n+1,0));
    rep(i,2){
        rep(j,n) cin >> v[i][j];
    }
    vector<vector<int>> dp(2,vector<int>(n+1,0));
    dp[0][0] = v[0][0];
    for(int i = 0;i < 2; i++){
        for(int j = 0; j < n; j++){
           if(i==0 && j!=0) dp[i][j] = dp[i][j-1] + v[i][j];
           else if(j!=0 && i==1) dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + v[i][j];
           else if(i==1) dp[i][j] = dp[i-1][j] + v[i][j];
        }
    }
    cout << dp[1][n-1] << endl;
    return 0;
}