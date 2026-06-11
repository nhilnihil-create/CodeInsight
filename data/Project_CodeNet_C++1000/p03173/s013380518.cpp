#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int nax = 401;
ll dp[nax][nax];

int main(){
	int n; cin >> n;
	vector<int> v(n);
	vector<ll> pref(n+1, 0);
	for (int i = 0; i < n; ++i) cin >> v[i], pref[i+1] = pref[i] + v[i];
	for(int l = n-1; l >= 0; --l){
		for (int r = l; r < n; ++r)
		{
			if(l != r){
				ll t = dp[l][l] + dp[l+1][r];
				for(int i = l+1; i < r; ++i){
					t = min(t, dp[l][i] + dp[i+1][r]);
				}
				dp[l][r] = t - pref[l] + pref[r+1];
			}
		}
	}
	cout << dp[0][n-1];
}