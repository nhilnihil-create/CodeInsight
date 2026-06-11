#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long

const lint MOD = 1e9 + 7;
const int MAX_N = 100005;
lint dp[MAX_N][4];

int main(){
    string s; cin >> s; int n = (int)s.size();
    dp[0][0] = 1;
    rep(i, n){
        int j = i + 1;
        if(s[i] == '?'){
            dp[j][0] = dp[j-1][0] * 3;
            repn(k, 3) dp[j][k] = dp[j-1][k-1] + (dp[j-1][k] * 3) % MOD;
        }
        else{
            rep(k, 4) dp[j][k] = dp[j-1][k];
            dp[j][s[i]-'A'+1] += dp[j-1][s[i]-'A'];
        }
        rep(k, 4) dp[j][k] %= MOD;
    }
    cout << dp[n][3] << endl;
}
