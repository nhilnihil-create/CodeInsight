#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;


#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

int n;
string p;

Int dp[3300][3300];
Int dp_sum[3300][3300];

int main(){
    cin >> n;
    cin >> p;
    dp[0][0] = 1;
    for(int i = 1;i < n;i++){

        for(int j = 0;j <= i-1;j++){
            dp_sum[i-1][j] = dp[i-1][j];
            if(j-1 >= 0)dp_sum[i-1][j] += dp_sum[i-1][j-1];
            dp_sum[i-1][j] %=MOD;
        }

        for(int j = 0;j <= i;j++){
            if(p[i-1] == '<'){

                //if(j)dp[i][j] = dp_sum[i-1][j-1];

                if(j)dp[i][j] = dp_sum[i-1][j-1];


                //for(int k=0; k<j; k++){
                //  dp[i][j] += dp[i-1][k];
                //}

            }else{

                //dp[i][j] = dp_sum[i-1][i-1];
                //if(j) dp[i][j] -= dp_sum[i-1][j-1];

                dp[i][j] = dp_sum[i-1][i-1];
                if(j)dp[i][j] -= dp_sum[i-1][j-1];

                //for(int k=j; k<=i-1; k++){
                //  dp[i][j] += dp[i-1][k];
                //}
            }
            dp[i][j] %= MOD;
        }
    }
    
    Int ans = 0;
    for(int i = 0;i < n;i++){
        ans += dp[n-1][i];
        ans %= MOD;
    }
    if(ans < 0)ans += MOD;
    cout << ans << endl;

  return 0;

rep(i, n){
  rep(j, n)cout<<dp[i][j]<<' ';
  cout<<endl;
}
cout<<"---"<<endl;
rep(i, n){
  rep(j, n)cout<<dp_sum[i][j]<<' ';
  cout<<endl;
}

    return 0;
}
