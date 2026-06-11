#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> a(m);
	for(int i = 0; i < m; i++){
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end(), greater<int>());
	vector<int> data = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	vector<ll> dp(n + 1, -100000);
	dp[0] = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j <= n; j++){
			int num = data[a[i]];
			if(j + num <= n) dp[j + num] = max(dp[j + num], dp[j] + 1);
		}
	}
	int keta = dp[n];
	string ans;
	for(int i = 0; i < keta; i++){
		for(int j = 0; j < m; j++){
			int num = data[a[j]];
			if(n - num >= 0 && dp[n - num] == dp[n] - 1){
				ans.push_back(a[j] + '0');
				n -= num;
				break;
			}
		}
	}
	cout << ans << endl;
}