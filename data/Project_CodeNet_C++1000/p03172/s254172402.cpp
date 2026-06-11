#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9+7;


int main(){
	int n, k; cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	vector<ll> dp(k+1, 0);
	dp[0] = 1;
	for(int &i : a){
		vector<ll> fake(k+1, 0);
		for(int j = k; j >= 0; --j){
			int tmp = dp[j];
			int L = 1 + j;
			int R = min(k, j  + i);
			if(L <= R){
				fake[L] += tmp; fake[L] %= mod;
				if(R < k){
					fake[R+1] -= tmp; if(fake[R+1] < 0) fake[R+1] += mod;
				}
			}
		}
		ll sum = 0;
		for(int i = 0; i <= k; ++i){
			sum += fake[i]; sum %= mod;
			dp[i] += sum; dp[i] %= mod;
		}
	}
	cout << dp[k];
}