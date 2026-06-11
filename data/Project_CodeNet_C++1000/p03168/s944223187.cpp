#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fi first
#define se second
#define pub push_back
#define pi pair<int,int>
#define all(v) (v).begin(), (v).end()
#define rep(i, l, r) for(int i=(int)(l);i<(int)(r);i++)
#define repd(i, l, r) for (int i=(int)(l);i>=(int)(r);i--)
#define clrg(i, l, r) for(int i=(int)(l);i<(int)(r);i++)vis[i]=0,v[i].clear();
int power(int x, unsigned int y){int res = 1;while (y > 0){ if (y & 1){res = res*x;} y = y>>1;x = x*x;}return res;}
int powermod(int x, unsigned int y, int p){int res = 1;x = x % p;while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1; x = (x*x) % p;}return res;}
#define print2d(mat,n,m){for(int i=0;i<(int)(n);i++){for(int j=0;j<(m);j++){cout<<mat[i][j]<<" ";}cout<< endl;}}
#define clr(a,x) memset(a,x,sizeof(a))
#define rr(v) for(auto &val:v)
#define print(v) for (const auto itr : v){cout<<itr<<' ';}cout<<"\n";
#define ln length()
#define sz size()
#define mod 1000000007
#define elif else if
#define ld long double
ld dp[3001][3001][2];
ld ar[3001][2];
int n;
ld solve(int i,int c,int h){
  if(i==n){
    return (ld)(c<=n/2?1:0);
  }
  if(dp[i][c][h]>=0)return dp[i][c][h];
  ld ans=0.0000;
  ans+=ar[i][h]*solve(i+1,c+(h==1),0);
  if(i<n-1)ans+=ar[i][h]*solve(i+1,c+(h==1),1);
  dp[i][c][h]=ans;
  return ans;
}
int32_t main(){
   cin>>n;
  rep(i,0,n){
    cin>>ar[i][0];
    ar[i][1]=1-ar[i][0];
  }
  rep(i,0,n+1)rep(j,0,n+1)dp[i][j][0]=-1,dp[i][j][1]=-1;
  ld ans=solve(0,0,0)+solve(0,0,1);
  cout<<fixed<<setprecision(11)<<ans<<"\n";
   return 0;
}
/*
Edge cases? n=1? a[i]<=0?
long vs int? 1LL? 64bits?
Re-read problem. Is it as easy as it seems?
KEEP CORRECTING AND SUBMITTING!
*/
