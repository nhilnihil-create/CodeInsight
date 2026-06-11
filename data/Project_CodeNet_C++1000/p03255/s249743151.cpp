#include <iostream>
#include <cstdio>
#define N 200005
using namespace std;

typedef unsigned long long ll;
ll n, X, s, mn = 1e18, x[N];
int main()
{
	int i, j, k;
	cin >> n >> X;
	for (i = 1; i <= n; i++) {
		scanf("%lld", &x[i]);
		x[i] += x[i - 1];
	}
	for (i = 1; i <= n; i++) {
		s = (x[n] - x[n - i]) * 2;
		for (j = n, k = 3; j > 0; j -= i, k += 2) {
			s += (x[j] - x[max(0, j - i)]) * k;
		}
		mn = min(mn, s + X * i);
	}
    cout << mn + X * n << endl;
    return 0;
}