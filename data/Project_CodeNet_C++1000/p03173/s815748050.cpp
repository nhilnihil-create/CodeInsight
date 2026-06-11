#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
const long long INF = 1e18;

ll n;
ll a[405], dp[405][405], pre[405];


int main(){
	cin >> n;
	pre[0] = 0;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		dp[i][i] = 0;
		pre[i] = pre[i - 1] + a[i];
	}
	ll ans = 0, tmp = 0;
	for(ll i = 2; i <= n; i++){
		for(ll l = 1; l <= n - i + 1; l++){
			ll r = l + i - 1;
			dp[l][r] = INF;
			for(ll k = l; k <= r; k++){
				dp[l][r] = dp[l][r] <  dp[l][k] + dp[k + 1][r] + pre[r] - pre[l - 1] ? dp[l][r] :  dp[l][k] + dp[k + 1][r] + pre[r] - pre[l - 1];
			}
		}
	}
	cout << dp[1][n] << endl; 
	return 0;
}