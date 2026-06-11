#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000;

bool P[MAX+1] = {false, false};

void sieve(int n) {
	fill(P+2, P+n+1, true);
	for (int i = 2; i*i <= n; ++i) {
		if (P[i]){
			for (int j = i*i; j <= n; j += i) {
				P[j] = false;
			}
		}
	}
}

int main() {
	sieve(MAX);
	int a[MAX+1] = {};
	for (int i = 3; i <= MAX; i += 2) {
		if (P[i] && P[(i+1) / 2]) a[i] = 1;
	}
	for (int i = 0; i < MAX; i++) {
		a[i+1] += a[i];
	}
	int Q;
	cin >> Q;
	for (int q = 0; q < Q; q++) {
		int l, r;
		cin >> l >> r;
		int ans = a[r] - a[l-1];
		cout << ans << endl;
	}
	return 0;
}