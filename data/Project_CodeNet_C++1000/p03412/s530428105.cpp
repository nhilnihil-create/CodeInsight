#include<iostream>
#include<algorithm>
using namespace std;

int const MAX = 200005;
int const MAX_A = 1 << 28;
long long a[MAX];
long long b[MAX];
long long c[MAX];

long long find(long long y, int p, int n) {
	long long t;
	t = 1 << p;
	long long x = y % (1 << (p + 1));
	return (lower_bound(c + 1, c + n + 1, 4 * t-x) - lower_bound(c + 1, c + n + 1, 3 * t-x) 
		+ lower_bound(c + 1, c + n + 1, 2 * t-x) 
		- lower_bound(c + 1, c + n + 1, t-x));
}


long long f(int p, int n) {
	for (int i = 1; i <= n; i++) {
		c[i] = a[i] % (1 << (p + 1));
	}
	sort(c + 1, c + n + 1);
	int cnt=0;
	for (int i = 1; i <= n; i++) {
		cnt += find(b[i], p, n);
	}
	return cnt;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	long long ans = 0;
	for (int i = 0; i <= 29; i++) {
		long long t = f(i, n) & 1;
		ans += t*(1 << i);
	}
	cout << ans << endl;
}
