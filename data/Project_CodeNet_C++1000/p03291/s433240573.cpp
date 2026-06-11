#include <bits/stdc++.h>
using namespace std;


#define int long long 


const int N = 2e5 + 7, mod = 1e9 + 7;


int a[N], w[N], c[N], pwr[N];

int32_t main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; string str; cin >> str; n = str.size();
	pwr[0] = 1;
	for(int i = 1; i <= n; i++) {
		a[i] = a[i - 1] + (str[i - 1] == 'A');
		w[i] = w[i - 1] + (str[i - 1] == '?');
		c[i] = c[i - 1] + (str[i - 1] == 'C');
		pwr[i] = (pwr[i - 1] * 3) % mod;
	}

	int ans = 0;

	for(int i = 1; i <= n; i++) if(str[i - 1] == 'B' || str[i - 1] == '?') {
		int lsum = pwr[w[i - 1]] * a[i - 1] % mod;
		if(w[i - 1]) {
			lsum += pwr[w[i - 1] - 1] * w[i - 1] % mod;
			lsum %= mod;
		}
		int rsum = pwr[w[n] - w[i]] * (c[n] - c[i]) % mod;
		if(w[n] - w[i]) {
			rsum += pwr[w[n] - w[i] - 1] * (w[n] - w[i]) % mod;
			rsum %= mod;
		}
		ans += lsum * rsum % mod;
		ans %= mod;
	}

	cout << ans << endl;
}