#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll dp[3][3];
ll a[10005];
ll b[10005];
int main() {
	ll ans = inf;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> dp[i][j];
			ans = min(ans, dp[i][j]);
		}
		a[i] = ans;
		ans = inf;
	}
	for (int i = 0; i < 3; i++) {
		b[i] = dp[0][i] - a[0];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (dp[i][j] != a[i] + b[j]) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}
