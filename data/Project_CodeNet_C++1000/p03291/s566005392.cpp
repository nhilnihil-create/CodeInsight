#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
ll dp[100005][4];

int main(void){
    string s;

    cin >> s;

    dp[0][0] = 1;

    rep(i, 0, s.length()){
        rep(j, 0, 4){
            if(s[i] == '?'){
                dp[i+1][j] += dp[i][j] * 3;
                dp[i+1][j] %= 1000000007;
            }else{
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= 1000000007;
            }
            if((s[i] == 'A' || s[i] == '?') && j == 0){
                dp[i+1][j+1] += dp[i][j];
                dp[i+1][j+1] %= 1000000007;
            }else if((s[i] == 'B' || s[i] == '?') && j == 1){
                dp[i+1][j+1] += dp[i][j];
                dp[i+1][j+1] %= 1000000007;
            }else if((s[i] == 'C' || s[i] == '?') && j == 2){
                dp[i+1][j+1] += dp[i][j];
                dp[i+1][j+1] %= 1000000007;
            }
        }
    }



    cout << dp[s.length()][3] % 1000000007 << endl;
    return 0;
}
