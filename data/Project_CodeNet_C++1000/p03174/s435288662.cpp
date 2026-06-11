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

#define MAXN 25

ll dp[1<<MAXN];
int a[MAXN][MAXN];

int main(){ 
  int n;cin>>n;
  rep(i, n)rep(j, n)cin>>a[i][j];

  dp[0]=1;
  rep(bit, 1<<n)rep(l, n){
    if((bit>>l) %2 == 0)continue;

    int bc = __builtin_popcount(bit)-1;
     dp[bit] += dp[bit - (1<<l)] * a[bc][l];
    dp[bit] %= MOD;
  }

  cout<<dp[(1<<n)-1]<<endl;

  return 0;
}
