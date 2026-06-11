#include<bits/stdc++.h>
using namespace std;

#define mod      1e9+7;
#define INF      1e9+9;
#define ps(x,y)  fixed<<setprecision(y)<<x
# define PI 3.14159265358979323846264338327950 L
typedef long long ll;
typedef unsigned long long ull;
vector<pair<ll,ll>> v[200005];
ll col[200005];
void dfs(ll r,ll p,ll d){
	if(d%2==1)
		col[r]=1;
	for(auto x: v[r]){
		if(x.first!=p){
			dfs(x.first,r,d+x.second);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	ll n;
	cin>>n;
	for(ll i=1;i<n;i++){
		ll a,b,w;
		cin>>a>>b>>w;
		v[a].push_back({b,w});
		v[b].push_back({a,w});
	}
	dfs(1ll,-1ll,0ll);
	for(ll i=1;i<=n;i++)
		cout<<col[i]<<endl;
	return 0;
}