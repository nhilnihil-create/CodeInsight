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
int arr[22][22];
int dp[22][3000000];
int vis[22][3000000];
// umap<int,umap<lli,int> >dp,vis;
lli fn(int i,lli bit) {
	if(i>n) return 1;
	if(vis[i][bit]) return dp[i][bit];
	vis[i][bit]=1;
	lli curr=0;
	fr(j,1,n) {
		if(arr[i][j] && !(((lli)1<<(j-1)) & bit))
			curr=(curr+fn(i+1,bit+((lli)1<<(j-1))))%mod;
	}
	return dp[i][bit]=curr;
}
int main(){
	jaldiKarNe;
	cin>>n;
	fr(i,1,n) fr(j,1,n) cin>>arr[i][j];
	cout<<fn(1,0);
}
