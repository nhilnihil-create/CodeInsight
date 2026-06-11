#include <iostream>
#define N_MAX 100000
using namespace std;

long long gcd(long long a, long long b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	while (a != 0) {
		long long tmp = b % a;
		b = a;
		a = tmp;
	}
	return b;
}

int main() {
	int n;
	cin >> n;
	int a[N_MAX+1];
	for (int i = 1; i <= n; i++) cin >> a[i];
	int L[N_MAX+2], R[N_MAX+2];
	L[0] = 0; R[n+1] = 0;
	for (int i = 1; i <= n; i++) {
		L[i] = gcd(L[i-1], a[i]);
	}
	for (int i = n; i >= 1; i--) {
		R[i] = gcd(R[i+1], a[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int now = gcd(L[i-1], R[i+1]);
		ans = max(ans, now);
	}
	cout << ans << endl;
	return 0;
}