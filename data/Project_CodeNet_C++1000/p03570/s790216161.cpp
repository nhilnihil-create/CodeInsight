#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 5;

string ss;
int dp[1<<26], ans[N];

int main(){
	cin>>ss;
	int n = ss.size(), cur = 0;
	fill(dp, dp+(1<<26), 1<<30);
	dp[cur] = 0;
	for(int i=0;i<n;i++){
		cur ^= (1<<(ss[i]-'a'));
		ans[i] = dp[cur]+1;
		for(int j=0;j<26;j++) ans[i] = min(ans[i], dp[cur ^ (1<<j)]+1);
		dp[cur] = min(dp[cur], ans[i]);
	}
	cout<<ans[n-1]<<'\n';
	return 0;
}