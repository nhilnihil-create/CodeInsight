#include <bits/stdc++.h>

using namespace std;

int main()
{

	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n,k;
	cin >>n>>k;
	vector<int> v(n+1);
	vector<bool> dp(k+1);
	for (int i = 1; i <=n; ++i) cin >> v[i];
	for(int i = k;i>=0;i--) {
		for(int j = n;j>=1;j--) {
			if(dp[i+v[j]]==0&&i+v[j]<=k) {
				dp[i] = 1;
				break;
			}
		}
	}
	if(dp[0]==1) cout << "First" <<'\n';
	else cout <<"Second"<<'\n';
	return 0;
}