#include <iostream>
#include <algorithm>
using namespace std;

long long N, C, x[100009], r[100009], c1[100009], c2[100009];

int main() {
	cin >> N >> C;
	for (int i = 1; i <= N; i++) cin >> x[i] >> r[i];
	long long maxn1 = 0, sum1 = 0;
	for (int i = 1; i <= N; i++) {
		sum1 += r[i]; maxn1 = max(maxn1, sum1 - x[i]);
		c1[i] = maxn1;
	}
	long long maxn2 = 0, sum2 = 0;
	for (int i = N; i >= 1; i--) {
		sum2 += r[i]; maxn2 = max(maxn2, sum2 - (C - x[i]));
		c2[i] = maxn2;
	}
	long long maxn3 = 0, sum3 = 0;
	for (int i = 1; i <= N; i++) {
		sum3 += r[i]; maxn3 = max(maxn3, (sum3 + c2[i + 1]) - x[i] * 2);
	}
	long long maxn4 = 0, sum4 = 0;
	for (int i = N; i >= 1; i--) {
		sum4 += r[i]; maxn4 = max(maxn4, (sum4 + c1[i - 1]) - (C - x[i]) * 2);
	}
	cout << max({ maxn1,maxn2,maxn3,maxn4 }) << endl;
	return 0;
}