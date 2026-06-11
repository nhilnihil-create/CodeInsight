#include <bits/stdc++.h>
using namespace std;

long long a[200010], tot[200010];

int main() {
	long long n,x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		tot[i] = tot[i-1]+a[i];
	}
	long long ans = tot[n]*5+x*n*2;
	for (int t = n-1; t >= 1; t--) {
		int k = n/t;
		//if  (n%t) k++;
		long long tmp = tot[n]*5+x*(n+t);
		int cur = n;
		while (cur)  {
			int l = cur-t;
			if (l >= 0) {
				if (cur < n) tmp += (tot[cur]-tot[l])*((n-cur)/t-1)*2;
				cur -= t;
			}
			else {
				tmp += tot[cur]*((n-cur)/t-1)*2;
				break;
			}
			if (tmp >= ans) break;
		}
		ans = min(ans,tmp);
	}
	cout << ans << "\n";
}