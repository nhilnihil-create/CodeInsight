#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n; cin>>n;
	vector<int> dp(n + 1, n);
	dp[0] = 0;
	for(int i = 0; i < n; i++){
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		int prd = 6;
		while(i + prd <= n){
			dp[i + prd] = min(dp[i + prd], dp[i] + 1);
			prd *= 6;
		}
		prd = 9;
		while(i + prd <= n){
			dp[i + prd] = min(dp[i + prd], dp[i] + 1);
			prd *= 9;
		}
	}
	cout<<dp[n]<<endl;

	return 0;
}