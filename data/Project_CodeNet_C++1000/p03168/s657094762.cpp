//Krunal_Mathukiya
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define li long int
#define pb push_back
#define mkp make_pair
#define nikalL return
#define umap unordered_map
#define fr(i,s,n) for(int i=s;i<=n;++i)
#define frr(i,s,n) for(int i=s;i>=n;--i)
#define jaldiKarNe ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
int n;
long double arr[3001];
long double dp[3001][3001];
int vis[3001][3001];
long double fn(int i,int tail) {
	if(i==0) {
		if(tail<=n/2) return 1;
		else return 0;
	}
	if(vis[i][tail]) return dp[i][tail];
	vis[i][tail]=1;
	long double curr=(1-arr[i])*fn(i-1,tail)+arr[i]*fn(i-1,tail-1);
	return dp[i][tail]=curr;
}
int main(){
	jaldiKarNe;
	cin>>n;
	fr(i,1,n) cin>>arr[i];
	cout<<fixed<<setprecision(10)<<fn(n,n);
}
