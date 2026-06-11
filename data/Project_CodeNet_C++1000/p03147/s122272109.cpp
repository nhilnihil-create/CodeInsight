#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int main() {
	int N, h[MAX];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> h[i];
	}
	int l, r;
	int ans = 0;
	while (true) {
		for (int i = 0;; i++) {
			if (h[i] != 0 || i == N) {
				l = i;
				break;
			}
		}
		for (int i = l;; i++) {
			if (h[i] == 0 || i == N) {
				r = i;
				break;
			}
		}
		if (l == N && r == N) {
			break;
		}
		for (int i = l; i < r; i++) {
			h[i]--;
		}
		ans++;
	}
	cout << ans << endl;
	return 0;
}
