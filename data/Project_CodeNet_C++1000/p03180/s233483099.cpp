#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define pb push_back 
using namespace std;
ll sc[1 << 16], dp[1 << 16][17], A[16][16];
ll fun(int mask, int k){
	if(mask == 0)
		return 0;
	if(dp[mask][k] != -1)
		return dp[mask][k];
	ll maxi = -1e18;
	for(int i = mask; i; i = (i - 1) & mask){
		maxi = max(maxi, sc[i] + fun(mask ^ i, k + 1));
	}
	return dp[mask][k] = maxi;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> A[i][j];
	for(int i = 0; i < (1 << n); i++){
		vector<int> df;
		for(int j = 0; j < n; j++){
			if(i & (1 << j))
				df.pb(j);
		}
		for(int p = 0; p < df.size(); p++)
		for(int q = p + 1; q < df.size(); q++){
			sc[i] += A[df[p]][df[q]];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << fun((1 << n) - 1, 0) << '\n';

}