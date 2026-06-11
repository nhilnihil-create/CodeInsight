#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[100010];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	sort(a, a + n);
	int first = a[n-1], dif = 1e9, second = -1;
	for (int i = 0; i < n-1; i ++) {
		if (second == -1 || abs((first+1)/2 - a[i]) < dif) {
			second = a[i];
			dif = abs(first/2 - a[i]);
		}
	}
	cout << first << ' ' << second << endl;
	return 0;
}