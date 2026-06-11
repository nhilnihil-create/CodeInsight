#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF 1e16
#define mod 1000000007

int N,K;
string S;
int dp[301][301][301];

int main(){
  cin>>S>>K;
  N=S.size();

  rep(i,301)rep(j,301)rep(k,301)dp[i][j][k]=-100000;
  rep(i,N+1){
    rep(k,K+1)dp[i][i][k]=0;
    if(i<N)rep(k,K+1)dp[i][i+1][k]=1;
  }

  repl(len,2,N+1){
    rep(l,N){
      ll r=l+len;
      if(r>N)continue;
      rep(k,K+1){
        maxch(dp[l][r][k],dp[l][r-1][k]);
        maxch(dp[l][r][k],dp[l+1][r][k]);
        if(S[l]==S[r-1])maxch(dp[l][r][k],dp[l+1][r-1][k]+2);
        if(k>0){
          maxch(dp[l][r][k],dp[l+1][r-1][k-1]+2);
          maxch(dp[l][r][k],dp[l][r][k-1]);
        }
      }
    }
  }



  cout<<dp[0][N][K]<<endl;
  return 0;
}
