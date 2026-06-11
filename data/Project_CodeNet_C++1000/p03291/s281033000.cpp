#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll one = 1;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    string S;
    cin >> S;
    int N = S.length();

    vector<vector<ll>> dp(N+1, vector<ll> (4, 0));
    if(S[0] == 'A'){
        dp[1][0] = 1;
        dp[1][1] = 1;
    }
    else if(S[0] == 'B'){
        dp[1][0] = 1;
        dp[1][1] = 0;
    }
    else if(S[0] == 'C'){
        dp[1][0] = 1;
        dp[1][1] = 0;
    }
    else if(S[0] == '?'){
        dp[1][0] = 3;
        dp[1][1] = 1;
    }

    for (int i = 2; i < N+1; i++) {
        if(S[i-1] == 'A'){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = (dp[i-1][1] + dp[i-1][0]) % MOD;
            dp[i][2] = dp[i-1][2];
            dp[i][3] = dp[i-1][3];
        }
        else if(S[i-1] == 'B'){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = (dp[i-1][2] + dp[i-1][1]) % MOD;
            dp[i][3] = dp[i-1][3];
        }
        else if(S[i-1] == 'C'){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2];
            dp[i][3] = (dp[i-1][3] + dp[i-1][2]) % MOD;
        }
        else if(S[i-1] == '?'){
            dp[i][0] = dp[i-1][0] * 3 % MOD;
            dp[i][1] = (dp[i-1][1] * 3 % MOD + dp[i-1][0]) % MOD;
            dp[i][2] = (dp[i-1][2] * 3 % MOD + dp[i-1][1]) % MOD;
            dp[i][3] = (dp[i-1][3] * 3 % MOD + dp[i-1][2]) % MOD;
        }
    }

    ll ans = dp[N][3];

    printf("%lld\n", ans);




}