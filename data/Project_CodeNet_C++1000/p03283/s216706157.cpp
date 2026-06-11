#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll sum[510][510];
int main(){
	ll n,m,q;
	cin>>n>>m>>q;
	while(m--){
		ll l,r;
		cin>>l>>r;
		sum[l][r]++;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)sum[i][j]+=sum[i][j-1];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)sum[i][j]+=sum[i-1][j];
	
	while(q--){
		ll a,b;
		cin>>a>>b;
		cout<<sum[b][b]+sum[a-1][a-1]-sum[a-1][b]-sum[b][a-1]<<endl;
	}
	return 0;
}
