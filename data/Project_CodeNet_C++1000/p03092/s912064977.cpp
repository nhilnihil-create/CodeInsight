#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const ll MAX_N = 5e3 + 15, inf = 1000000LL * 1000000LL * 1000000LL;
ll n, L, R, ans = inf, ind = 0;
ll IND[MAX_N];
ll Arr[MAX_N];
ll cntl[MAX_N][MAX_N];
ll cntb[MAX_N][MAX_N];

ll dp[MAX_N];

void processMin() {
	for (ll i = 0; i < n; i++) {
		ll l = 0, b = 0;
		for (ll j = i - 1; 0 <= j; j--) {
			l += (Arr[j] < Arr[i]);
			b += (Arr[j] > Arr[i]);
			
			cntl[i][j] = l;
			cntb[i][j] = b;
		}
	}
	
	for (ll i = 0; i < n; i++) {
		ll l = 0, b = 0;
		for (ll j = i + 1; j < n; j++) {
			l += (Arr[j] < Arr[i]);
			b += (Arr[j] > Arr[i]);
			
			cntl[i][j] = l;
			cntb[i][j] = b;
		}
	}
}

int main() {
//	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> L >> R;
	swap(L, R);
	
	for (ll i = 0; i < n; i++) {
		cin >> Arr[i];
		
		IND[Arr[i]] = i;
	}
	
	processMin();
	
	ind = Arr[0];
	for (ll i = 1; i < n; i++) {
		if (ind > Arr[i]) {
			dp[i] = cntb[i][0] * R;
			ind = Arr[i];
		}
		else
			dp[i] = inf;
			
		int Max = -1;
		for (ll j = i - 1; ~j; j--)
			if (Arr[j] < Arr[i] && Arr[j] > Max) {
				ll l = min(cntl[j][i - 1], cntl[i][j + 1]);
				ll b = min(cntb[j][i - 1], cntb[i][j + 1]);
				
				dp[i] = min(dp[i], dp[j] + l * L + b * R);
				Max = Arr[j];
			}
	}
	
	ind = -1;
	for (ll i = n - 1; ~i; i--) {
		if (Arr[i] > ind) {
			ans = min(ans, dp[i] + cntl[i][n - 1] * L);
			ind = Arr[i];
		}
	}
	
	cout << ans << "\n";
	return 0;
}