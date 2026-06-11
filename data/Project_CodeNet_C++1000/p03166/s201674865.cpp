#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long int
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
vector<int> topsort,vis(100005),v[100005],v1[100005];
   int dp[100005+1];
void dfs(int node,int c){
  vis[node]=1;
    rr(v[node]){
      if(!vis[val]){
        dfs(val,c+1);
      }
    }
    topsort.push_back(node);
}
int32_t main(){
   int n; cin>>n;
   int m; cin>>m;
  topsort.pub(0);
    clr(dp,0);
  rep(i,0,m){
    int a,b; cin>>a>>b;
    v[a].pub(b);
    v1[b].pub(a);
  }
  rep(i,1,n+1)if(!vis[i])dfs(i,0);
  int ans=0;
  reverse(topsort.begin()+1,topsort.end());
  rep(i,1,topsort.sz){
      rr(v[topsort[i]]){
        dp[val]=max(dp[val],dp[topsort[i]]+1);
      }
  }
  rep(i,0,n+1)ans=max(ans,dp[i]);
  cout<<ans<<"\n";
   return 0;
}
/*
Edge cases? n=1? a[i]<=0?
long vs int? 1LL? 64bits?
Re-read problem. Is it as easy as it seems?
KEEP CORRECTING AND SUBMITTING!
*/
