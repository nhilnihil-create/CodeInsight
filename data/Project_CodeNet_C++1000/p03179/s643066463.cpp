#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for(int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    int n; cin >> n;
    ll MOD = 1e9+7;
    string s; cin >> s;

    ll dp[n+1][n+1];
    rep(i,n+1)rep(j,n+1)dp[i][j] = 0;
    srep(j,1,n+1) dp[1][j] = 1; 

    srep(i,2,n+1){
        char c = s[i-2];
        if(c == '>'){
            ll sum = dp[i-1][n+2-i];
            drep(j,n+2-i){
                if(j == 0)break;
                dp[i][j] = sum;
                sum = (sum + dp[i-1][j]) % MOD;
            }
        }else{
            ll sum = 0;
            srep(j,1,n+2-i){
                sum = (sum + dp[i-1][j]) % MOD;
                dp[i][j] = sum;
            }
        }
    }

    cout << dp[n][1] << endl;
    return 0;
}


