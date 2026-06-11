#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mxn 100005
#define mp make_pair
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long int ll;
int main(){
	int n; cin>>n;
	ll ar1[n],ar2[n],ar3[n];
	for(int i=0; i<n; i++){
	     cin>>ar1[i]>>ar2[i]>>ar3[i];
	}
	ll dp[n][3];
	dp[0][0] = ar1[0];
	dp[0][1] = ar2[0];
	dp[0][2] = ar3[0];
	for(int i=1; i<n; i++){
		dp[i][0] = max(dp[i-1][1]+ar1[i], dp[i-1][2]+ar1[i]);
		dp[i][1] = max(dp[i-1][0], dp[i-1][2])+ar2[i];
		dp[i][2] = max(dp[i-1][0], dp[i-1][1])+ar3[i];
	}
	cout<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
}