#include<bits/stdc++.h>
using namespace std;

// Vasito
typedef long long ll;
typedef pair<int,int> pii;
#define fore(i,ii,iii)for(int i=ii;i<iii;i++)
#define rfor(i,ii,iii)for(int i=iii-1;i>=ii;i--)
#define all(s) s.begin(),s.end()
#define sz(a) ((int)a.size())
#define pb push_back
#define mset(a,b) memset(a,b,sizeof(a))
#define fst first
#define snd second
// Extra
#define OUT(a)cout<<a<<endl
#define ANS(a) OUT(res.size());for(auto i:a)cout<<i<<" ";ENDL
#define PRINT(a,init,end) FOR(i,init,end) cout<<a[i]<<" ";ENDL
#define PRINTV(a) for(auto i:a)cout<<i<<" ";ENDL

struct block {ll w,s,v;};
const ll N=1024,M=1e4+15,MOD=1e9+7,INF=1e18;
block a[N];
ll n,m,dp[N][M];
  
bool compare(const block &a,const block &b) {
  return (a.w+a.s)<(b.w+b.s);
}

ll solve(int i,int j) {
  if(i==n) return 0;
  if(j>=M)return 0;
  if(dp[i][j]!=-1) return dp[i][j];
  ll r = solve(i+1,j);
  if(a[i].s>=j) r=max(r,a[i].v+solve(i+1,j+a[i].w));
  return dp[i][j] = r;
}

int main() {
  ios::sync_with_stdio(false);
  mset(dp,-1);
  cin>>n;
  fore(i,0,n)cin>>a[i].w>>a[i].s>>a[i].v;
  sort(a,a+n,compare);
  //cout<<"___________"<<endl;fore(i,0,n)cout<<a[i].w<<" "<<a[i].s<<" "<<a[i].v<<endl;
  cout<<solve(0,0)<<endl;
}