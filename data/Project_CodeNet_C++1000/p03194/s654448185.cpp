#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> prime, pw;
int n, p, ans = 1;

inline void f(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			prime.push_back(i);
			int res = 0;
			while (n % i == 0) {
				n /= i;
				res++;
			}
			pw.push_back(res);
		}
	}
	if (n != 1) {
		prime.push_back(n);
		pw.push_back(1);	
	}
}

int32_t main() {
	cin >> n >> p;
	f(p);
	for (int i = 0; i < prime.size(); i++) {
		for (int j = 0; j < pw[i] / n; j++)
			ans *= prime[i];
	}
	return cout << ans, 0;
}