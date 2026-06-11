#include <iostream>
#include <cstdio>
using namespace std;

typedef unsigned long long ll;
ll n, mn=1e18, X, s, k, a[200005], b[200005];
int main()
{
	int i, j;
	cin >> n >> X;
	for (i = 1; i <= n; i++) {
		scanf ("%lld", &a[i]);
		a[i] += a[i - 1];
	}
	for (i = 1; i <= n; i++) {
		s = (n + i) * X ;
		k = 5;
		for (j = n; j >= 1; j -= i) {
			s += (a[j] - a[max(j - i, 0)]) * k;
			if(j < n) k += 2;
		}
		mn = min(mn, s);
	}
	cout << mn;
    return 0;
}

//	mn = a[n] * 5 + X * 3;

//	b[1] = b[2] = 5;
//	for (i = 3; i <= n; i++) b[i] = b[i - 1] + 2;
//	for (i = n; i >= 1; i--) {
//		mn += a[i] * b[i];
//	}
