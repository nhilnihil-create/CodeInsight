#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

int n;
char s[N];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	if (s[n] == '1' || (s[1] == '0' && n > 1)) {
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= (n >> 1); i++) {
		if (s[i] ^ s[n - i]) {
			puts("-1");
			return 0;
		}
	}
	if (n == 1)
		return 0;
	vector<int> goal;
	for (int i = 1; i <= ((n + 1) >> 1); i++) {
		if (s[i] == '1') {
			goal.push_back(i);
		}
	}
	goal.push_back(n);
	int ls;
	for (auto sz : goal) {
		if (sz == 1) {
			ls = 1;
		} else {
			printf("%d %d\n", sz, ls);
			for (int i = ls + 1; i < sz; i++)
				printf("%d %d\n", sz, i);
			ls = sz;
		}
	}
	return 0;
}
