#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin>>n;
	vector<int>d(200010);
	bitset<4000010>dp;
	int sum=0;
	dp[0]=1;
	for(int i=0; i<n; i++) {
		cin>>d[i];
		sum+=d[i];
		dp|=dp<<d[i];
	}
	int odd=sum%2;
	for(int i=sum/2+odd; i<4000010; i++) {
		if(dp[i]) {
			cout<<i;
			return ;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}