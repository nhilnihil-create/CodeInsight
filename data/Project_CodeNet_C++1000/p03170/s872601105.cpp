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
int dp[100005][2];
int n;
vector<int> v;
int solve(int p,int s){
    if(s<0){
        return (p%2?0:1);
    } 
    if(dp[s][p%2]!=-1)return dp[s][p%2];
    int ans=0;
    if(p%2==0){
        int c=0;
        rep(j,0,n){
           c+=solve(p+1,s-v[j]);
        }
        if(c>0)ans=1;
    }
    else{
        int c=0;
        rep(j,0,n){
            c+=(solve(p+1,s-v[j])==0);
        }
        if(c>0)ans=0;
        else ans=1;
    }
    dp[s][p%2]=ans;
    return ans;
}
int32_t main(){
   int k; cin>>n>>k;
    clr(dp,-1);
    rep(i,0,n){
        int t; cin>>t;
        v.pub(t);
    }
    if(solve(0,k))cout<<"First\n";
    else cout<<"Second\n";
   return 0;
}
/*
Edge cases? n=1? a[i]<=0?
long vs int? 1LL? 64bits?
Re-read problem. Is it as easy as it seems?
KEEP CORRECTING AND SUBMITTING!
*/
