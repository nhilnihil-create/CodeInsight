#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

# define MAXN 21

// dp[s]:左からbitcount(s)人の男とペアを組ませる、女性のピックがSの時のパターン数
ll dp[1<<(MAXN+1)];
int a[MAXN+1][MAXN+1];

int main(){
  int n;cin>>n;
  rep(i, n)rep(j, n)cin>>a[i][j];

  dp[0]=1;
  rep1(s, (1<<n)-1)rep(l, n){
    if((s>>l)%2==0)continue;

    int g = __builtin_popcount(s);
    int pre_s = s - (1<<l);
    if( a[g-1][l] ){
      dp[s] += dp[pre_s];
      dp[s] %= MOD;
    }
//cout<<g<<' '<<l<<' '<<s<<endl;
  }

  cout<<dp[(1<<n)-1]<<endl;

  return 0;
}