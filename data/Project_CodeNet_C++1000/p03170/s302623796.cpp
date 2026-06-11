#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define mod 1000000007
#define int long long

void solve() {
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	int i;
	for(i=0;i<n;i++)cin>>a[i];

	int j;
	vector<int> dp(k+1);
	dp[0] = 0;
	for(i=1;i<=k;i++){
		int t = 0;
		for(j=0;j<n;j++){
			if(i-a[j] >= 0)if(dp[i-a[j]] == 0){
				t = 1;
				break; 
			}
		}
		dp[i] = t;
	}


	if(dp[k] == 1)cout<<"First"<<endl;
	else cout<<"Second"<<endl;

	return;
}

int32_t main() {
	std::ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	solve();
	return 0;
}
