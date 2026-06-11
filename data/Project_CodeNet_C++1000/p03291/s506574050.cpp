#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
 
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(a) (a).begin(),(a).end()

#define  MOD 1000000007
int main(){
    string s;
    cin >> s;

    ll dp[100010][5];
    rep(i, 100010)rep(j, 5)dp[i][j] = 0;
    dp[0][0] = 1;

    rep(i, s.size()){
        rep(j, 5){
            if(s[i] == '?')dp[i+1][j] = (dp[i+1][j] + dp[i][j]*3%MOD)%MOD;
            else dp[i+1][j] = (dp[i+1][j] + dp[i][j])%MOD;
        }
        if(s[i] == 'A' || s[i] == '?')dp[i+1][1] = (dp[i+1][1] + dp[i][0])%MOD;
        if(s[i] == 'B' || s[i] == '?')dp[i+1][2] = (dp[i+1][2] + dp[i][1])%MOD;
        if(s[i] == 'C' || s[i] == '?')dp[i+1][3] = (dp[i+1][3] + dp[i][2])%MOD;
    }

    cout << dp[s.size()][3] << endl;
}
