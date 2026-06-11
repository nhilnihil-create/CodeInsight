#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,MOD=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,vis[mxN];
int dp[2][mxN];
vi adj[mxN];
void solve(int i,int p){
    if(dp[0][i]!=-1)return;
    int cnt1=1,cnt2=1;
    for(int j:adj[i]){
        if(j!=p){
            solve(j,i);
            cnt1=(cnt1*dp[0][j])%MOD;
            cnt2=(cnt2*(dp[0][j]+dp[1][j])%MOD)%MOD;
        }

    }
    dp[1][i]=cnt1%MOD;
    dp[0][i]=cnt2%MOD;
    return;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    solve(0,-1);
    cout<<(dp[0][0]+dp[1][0])%MOD<<"\n";
}