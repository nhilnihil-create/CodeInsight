#include <bits/stdc++.h>
#define boost_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define debug(x) cout<<#x<<":"<<x<<" "
#define all(a) (a).begin(), (a).end()
#define cast static_cast
#define vi vector<int>
#define v vector
#define p pair
#define pb push_back
#define mk make_pair
typedef long long int ll;
typedef long double ld;
typedef double d;
using namespace std;
ll modF=1e9+7;
ll INF=1e11;

void solve(){
	int n,k;
	cin>>n>>k;
	vi a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	v<v<ll>> dp(n+1,v<ll>(k+1));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			if(j==0){
				dp[i][j]=1;
			}
			else if(i==0){
				dp[i][j]=dp[i][j-1];
			}
			else{
				int h=j-a[i-1];
				if(h<=0)
					dp[i][j]=(dp[i-1][j]+dp[i][j-1])%modF;
				else
					dp[i][j]=(dp[i-1][j]-dp[i-1][h-1]+dp[i][j-1]+modF)%modF;
			}
		}
	}
	if(k==0){
		cout<<1<<"\n";
		return;
	}
	cout<<(dp[n][k]-dp[n][k-1]+modF)%modF<<"\n";
}

int main(){
	solve();
	return 0;
}