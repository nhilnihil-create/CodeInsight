#include<bits/stdc++.h>
using namespace std;
int n,k;
const int INF = numeric_limits<int>::max();
int h[100005];
int dp[200005];

int main(){
	cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>h[i];
	for(int i=1; i<=n; i++) dp[i] = INF;
	dp[1] = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=k; j++){
			dp[i+j] = min(dp[i+j],abs(h[i]-h[j+i])+dp[i]);
		}
	}
	cout<<dp[n];
}