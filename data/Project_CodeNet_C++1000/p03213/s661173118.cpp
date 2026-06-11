#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 105;

int n;
int cnt[N];

int main() {

	FAST;

	cin >> n;
	for (int i = 2; i <= n; i ++) {
		int tmp = i;
		for (int j = 2; j * j <= i; j ++) {
			while (tmp % j == 0) {
				tmp /= j;
				cnt[j] ++;
			}
		}
		if (tmp != 1) cnt[tmp] ++;
	}
	int ans = 0;
	for (int i = 2; i <= n; i ++) {
		if (cnt[i] >= 74) ans ++;
	}
	for (int i = 2; i <= n; i ++) {
		for (int j = 2; j <= n; j ++) {
			if (i != j && cnt[i] >= 2 && cnt[j] >= 24) ans ++;
		}
	}
	for (int i = 2; i <= n; i ++) {
		for (int j = 2; j <= n; j ++) {
			if (i != j && cnt[i] >= 4 && cnt[j] >= 14) ans ++;
		}
	}
	for (int i = 2; i <= n; i ++) {
		for (int j = 2; j < i; j ++) {
			for (int k = 2; k <= n; k ++) {
				if (k != i && k != j && cnt[k] >= 2 && cnt[i] >= 4 && cnt[j] >= 4) ans ++; 
			}
		}
	}
	cout << ans << '\n';
	return 0;
}