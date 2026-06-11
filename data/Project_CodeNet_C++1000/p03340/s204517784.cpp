
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}

	int j = -1;
	long long xor_sum = 0, sum = 0;
	long long ret = 0;
	for (int i = 0; i < n; i++) {
		while (j + 1 < n && (xor_sum^a[j + 1]) == sum + a[j + 1]) {
			xor_sum ^= a[j + 1];
			sum += a[j + 1];
			j++;
		}
		ret += j - i + 1;
		xor_sum ^= a[i];
		sum -= a[i];
	}
	cout << ret << endl;
	return 0;
}