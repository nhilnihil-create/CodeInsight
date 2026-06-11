#include <bits/stdc++.h>
using namespace std;
#define maxn 1000000

int pri[maxn + 10];
int f[maxn + 10];

int main() {
	long long n, p; cin >> n >> p;
	memset(f, 0, sizeof(f)); pri[0] = 0;
	for (int i = 2; i <= maxn; i ++)
		if (!f[i]) {
			pri[++pri[0]] = i;
			for (int j = 2*i; j <= maxn; j += i) f[j] = 1; 
		}
	long long ans = 1; 
	for (int i = 1; i <= pri[0]; i ++)
		if (pri[i] <= p) {
			int t = 0;
			while (p % pri[i] == 0 && p >= pri[i]) { p /= pri[i]; t ++; }
			ans *= pow(pri[i], t / n);
		} else break;
	if (p > 1) ans *= pow(p, 1/n);
	cout << ans << endl;
	return 0;
}