#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

ll pow(ll a, ll b, ll m)
{
    ll  ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}
const ll INF=1e15;
int a[405];
ll pre[405];
ll dp[405][405];

ll solve(int ini,int fin){
    //if(inf>fin) return INF;
	if(dp[ini][fin] != -1) return dp[ini][fin];
	if(ini==fin) return dp[ini][fin] = 0;
	if(ini + 1 == fin) return dp[ini][fin] = a[ini]+a[fin];

	ll best = INF;

	for(int i = ini;i<fin;i++){
		ll cand = solve(ini,i) + solve(i+1,fin)+pre[fin]-pre[ini-1];
		best = min(best,cand);
	}

	return dp[ini][fin] = best;

}

int main()
{
	IOS;
	int t=1; //cin>>t;
	while(t--){
	    memset(dp,-1,sizeof(dp));
	    int n; cin>>n;
	    for(int i=1;i<=n;i++) cin>>a[i];
	    pre[0]=0;
	    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	    cout<<solve(1,n);
	    cout<<endl;
	}  
}