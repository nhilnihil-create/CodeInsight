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
ll INF=1e18;

void solve(){
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	v<ll> pre(n);
	pre[0]=a[0];
	for(int i=1;i<n;i++){
		pre[i]=a[i]+pre[i-1];
	}
	v<v<ll>> dp(n,v<ll>(n));
	for(int i=n-1;i>=0;i--){
		for(int j=0;i+j<n;j++){
			if(j==0){
				dp[i][j]=0;
			}
			else if(j==1){
				dp[i][j]=a[i]+a[i+1];
			}
			else{
				ll min=INF;
				for(int k=0;k<j;k++){
					ll h;
					if(i!=0)
						h=dp[i][k]+dp[i+k+1][j-k-1]+pre[i+j]-pre[i-1];
					else
						h=dp[i][k]+dp[i+k+1][j-k-1]+pre[i+j];
					if(h<min){
						min=h;
					}
				}
				dp[i][j]=min;
			}
		}
	}
	cout<<dp[0][n-1]<<"\n";
}	

int main(){
	boost_io;
	cout<<setprecision(10);
	solve();
	return 0;
}
