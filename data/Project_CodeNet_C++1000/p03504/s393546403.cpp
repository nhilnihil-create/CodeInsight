#include<cstdio>
using namespace std;

int n, c, s[100000], t[100000], cc[100000], sm[200002], tt[200002];

int main() {
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &s[i], &t[i], &cc[i]);
	}

	for (int i = 1; i <= c; i++) {
		for (int j = 0; j < 200002; j++)tt[j] = 0;
		for (int j = 0; j < n; j++)if (cc[j] == i)tt[s[j] * 2 - 1]++, tt[t[j] * 2]--;
		for (int j = 1; j < 200002; j++)tt[j] += tt[j - 1];
		for (int j = 0; j < 200002; j++)if (tt[j] > 0)sm[j]++;
	}
	int mx = 0;
	for (int j = 0; j < 200002; j++)if (mx < sm[j])mx = sm[j];
	printf("%d\n", mx);

	return 0;
}