#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define pi pair<int,int>
bool comparator(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
    return a.ss.ss < b.ss.ss;
}

string s;
int dp[3005][3005];

int init(int n){
    dp[n-1][1] = 1 ;
    for(int i = 2 ; i<= n ; i++) dp[n-1][i] = 0;
    for(int i = n-2 ; i>=0 ; i--){
        for(int j = 1 ; j <= n-i ; j++){
            if(s[i] == '<'){
                dp[i][j] = dp[i+1][j-1];
            }
            else {
                dp[i][j] = (mod + dp[i+1][n-i-1] - dp[i+1][j-1])%mod;
            }
        }
        for(int j = 2 ; j <= n-i ; j++) dp[i][j] = (dp[i][j]+dp[i][j-1])%mod;
    }
    cout << dp[0][n] << endl;
}


int32_t main(){
    int n;
    cin >> n;
    memset(dp,0,sizeof(dp));
    cin >> s;
    init(n);
}
