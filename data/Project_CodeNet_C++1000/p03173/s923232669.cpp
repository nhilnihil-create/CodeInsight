//Krunal_Mathukiya
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define li long int
#define pb push_back
#define mkp make_pair
#define nikalL return
#define chalavo continue
#define basHo break
#define umap unordered_map
#define fr(i,s,n) for(int i=s;i<=n;++i)
#define frr(i,s,n) for(int i=s;i>=n;--i)
#define jaldiKarNe ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
int n;
lli arr[402];
lli pre[402];
lli dp[402][402];
int vis[402][402];
// {length,cost}
lli fn(int i,int j) {
	if(i==j) return 0;
	if(vis[i][j]) return dp[i][j];
	vis[i][j]=1;
	lli cost=1e18;
	lli len=pre[j]-pre[i-1];
	fr(mid,i,j-1) cost=min(cost,fn(i,mid)+fn(mid+1,j)+len);
	return dp[i][j]=cost;
}
int main(){
	jaldiKarNe;
	cin>>n;
	fr(i,1,n) cin>>arr[i];
	fr(i,1,n) pre[i]=pre[i-1]+arr[i];
	cout<<fn(1,n);
}