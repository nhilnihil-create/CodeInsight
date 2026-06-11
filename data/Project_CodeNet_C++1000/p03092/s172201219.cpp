#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSR(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int n,p[5005];
ll dp[5005][5005],A,B;

int main(){
	cin>>n>>A>>B;
	for(int i=1;i<=n;i++) cin>>p[i];
	rep(i,5005)rep(j,5005) dp[i][j] = 1e18;
	dp[0][0] = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			if(dp[i-1][j] > 1e17) continue;
			if(p[j] < p[i]){
				dp[i][i] = min(dp[i-1][j],dp[i][i]);
			}
			if(p[j] < p[i]){
				dp[i][j] = min(dp[i-1][j]+A,dp[i][j]);
			}
			if(p[j] > p[i]){
				dp[i][j] = min(dp[i-1][j]+B,dp[i][j]);
			}
		}
	}
	ll ans = 1e18;
	for(int i=0;i<5005;i++) ans = min(ans,dp[n][i]);
	cout << ans << endl;
}