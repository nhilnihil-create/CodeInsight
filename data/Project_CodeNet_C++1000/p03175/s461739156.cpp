#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define Fo(i,k,n) for(i=k;k<n?i<=n:i>=n;k<n?i+=1:i-=1)
#define endl '\n'
#define MOD 1000000007//998244353
#define pbb push_back
#define mpp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
ll dp[100005][2];
ll answer(ll u,ll par,ll col,vi* graph){
    if(dp[u][col]>=0) return dp[u][col];
	ll ans=1;
	for(auto v:graph[u]){
        if(v==par) continue;
		if(col==0){
            ans*=answer(v,u,1,graph);
        }else{
            ans*=answer(v,u,0,graph)+answer(v,u,1,graph);
        }
        ans%=MOD;
	}
	return dp[u][col]=ans;
}
void solve(ll caseno){
	ll i,n,x,y,ans;
	cin>>n;
	vi* graph = new vi[n];
	fo(i,0,n-1){
		cin>>x>>y;
		x--;y--;
		graph[x].pbb(y);
		graph[y].pbb(x);
	}
    mset(dp,-1);
	ans = answer(0,-1,0,graph) + answer(0,-1,1,graph);
    ans%=MOD;
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	//cin>>t;
	for(ll i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}
