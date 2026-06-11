#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int d[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, m;
	cin>>n>>m;
	vector<int> a(m);
	for(int i = 0; i < m; i++){
		cin>>a[i];
	}
	sort(a.rbegin(), a.rend());
	vector<int> dp(n + 1, -1e6);
	dp[0] = 0;
	for(int i = 1; i <= n; i++){
		for(auto x : a){
			if(d[x] <= i)dp[i] = max(dp[i], dp[i - d[x]] + 1);
		}
	}
	string ans = "";
	int ind = n;
	while(true){
		bool flg = false;
		for(auto x : a){
			if(d[x] <= ind && dp[ind] == dp[ind - d[x]] + 1){
				ans += char(x + '0');
				ind -= d[x];
				flg = true;
				break;
			}
		}
		if(!flg)break;
	}
	cout<<ans<<endl;

	return 0;
}