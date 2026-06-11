#include <iostream>
#include <vector>
#include <algorithm>
#define INF (1LL<<50LL)

typedef long long ll;

using namespace std;

ll n;
ll a,b;

int main() {
	cin >> n >> a >> b;
	vector<ll> arr(5001);
	vector<ll> dp(5001);
	for(int i = 0; i < n; i++) {
		int p;
		cin >> p;
		arr[p] = i+1;
	}
	for(int num = 1; num <= n; num++) {
		int pos = arr[num];
		ll temp_min = INF;
		for(int i = 0; i <= n; i++) {
			temp_min = min(temp_min,dp[i]);
			if(pos>i) {
				dp[i] = temp_min+b;
			}
			if(pos==i) {
				dp[i] = temp_min;
			}
			if(pos<i) {
				dp[i] = temp_min+a;
			}
			//cout << dp[i] << endl;
		}
		//cout << "-----" << endl;
	}
	ll ans = INF;
	for(int i = 0; i <= n; i++) {
		ans = min(ans,dp[i]);
	}
	cout << ans << endl;
}
