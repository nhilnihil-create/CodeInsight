#include <iostream>
using namespace std;

bool isprime[100001];
int cnt[100001];

int main() {
	int i, j;
	
	for (i = 2; i <= 100000; i++) isprime[i] = true;
	for (i = 2; i * i <= 100000; i++) {
		if (isprime[i]) {
			for (j = i * 2; j <= 100000; j += i) {
				isprime[j] = false;
			}
		}
	}
	
	for (i = 1; i <= 100000; i += 2) {
		if (isprime[i] && isprime[(i + 1) / 2]) {
			cnt[i] = 1;
		}
	}
	
	for (i = 1; i <= 100000; i++) cnt[i] += cnt[i - 1];
	
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << cnt[r] - cnt[l - 1] << endl;
	}
	return 0;
}