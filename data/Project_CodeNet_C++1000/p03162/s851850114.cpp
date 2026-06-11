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
int dp[100005][5],n;
vector<int> a,b,c;
int solve(int i,int act){
  if(i==n)return 0;
  if(dp[i][act]!=-1)return dp[i][act];
  int ans=0;
  if(act==0){
    ans=max(ans,solve(i,1));
    ans=max(ans,solve(i,3));
    ans=max(ans,solve(i,2));
  }
  elif(act==1){
      ans=max(ans,a[i]+solve(i+1,3));
      ans=max(ans,a[i]+solve(i+1,2));
  }
  elif(act==2){
       ans=max(ans,b[i]+solve(i+1,3));
        ans=max(ans,b[i]+solve(i+1,1));
  }
  elif(act==3){
       ans=max(ans,c[i]+solve(i+1,1));
      ans=max(ans,c[i]+solve(i+1,2));
  }
  dp[i][act]=ans;
  return ans;
}
int32_t main(){
   cin>>n;
   rep(i,0,n){
     int t; cin>>t;
     a.pub(t);
     cin>>t; b.pub(t);
     cin>>t; c.pub(t);
   }
   clr(dp,-1);
   cout<<solve(0,0);
   return 0;
}
/*
Edge cases? n=1? a[i]<=0?
long vs int? 1LL? 64bits?
Re-read problem. Is it as easy as it seems?
KEEP CORRECTING AND SUBMITTING!
*/
