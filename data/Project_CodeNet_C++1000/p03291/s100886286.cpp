#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

ll dp[100010][4];

int main(){
    string S; cin >> S;
    int N = S.size();
    dp[0][0] = 1;
    rep(i,N){
        rep(j,4){
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= MOD;
        }
        if(S[i] == 'A'){
            dp[i+1][1] += dp[i][0];
            dp[i+1][1] %= MOD;
        }
        if(S[i] == 'B'){
            dp[i+1][2] += dp[i][1];
            dp[i+1][2] %= MOD;
        }
        if(S[i] == 'C'){
            dp[i+1][3] += dp[i][2];
            dp[i+1][3] %= MOD;
        }
        if(S[i] == '?'){
            dp[i+1][1] += dp[i][0];
            dp[i+1][1] %= MOD;
            dp[i+1][2] += dp[i][1];
            dp[i+1][2] %= MOD;
            rep(j,4){
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= MOD;
            }
            dp[i+1][3] += dp[i][2];
            dp[i+1][3] %= MOD;
            rep(j,4){
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= MOD;
            }
        }
    }
    cout << dp[N][3] << endl;
}

