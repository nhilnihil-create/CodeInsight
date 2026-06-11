#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
using ll = long long;

bool a[100010]; // false: prime_number
int c[100010];

int main() {
	int Q;
	cin >> Q;
	for (int i = 2; i <= 100000; i++) {
		if (!a[i]) {
			for (int j = i + i; j <= 100000; j += i) a[j] = true;
		}
	}
	for (int i = 3; i <= 100000; i += 2) {
		if (!a[i] && !a[(i + 1) / 2]) c[i]++;
	}
	for (int i = 3; i <= 100000; i++) c[i] += c[i - 1];
	for (int q = 0; q < Q; q++) {
		int l, r;
		cin >> l >> r;
		cout << c[r] - c[l - 1] << endl;
	}
	return 0;
}