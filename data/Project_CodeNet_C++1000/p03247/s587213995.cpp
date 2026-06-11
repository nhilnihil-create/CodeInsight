#include <bits/stdc++.h>
 //for study source code by other coder
using namespace std;
 
#define M 33
 
int n, z;
long long x[1005], y[1005];
char ans[40];
set<int> s;
 
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", x + i, y + i);
		s.insert(abs(x[i] + y[i]) & 1);
	}
	if (s.size() == 2)
		printf("-1\n");
	else {
		z = *s.begin();
		if (z) {
			printf("%d\n", M);
			for (int i = 0; i < M; i++)
				printf("%lld%c", 1LL << i, i == M - 1 ? '\n' : ' ');
		} else {
			printf("%d\n", M + 1);
			for (int i = 0; i < M; i++)
				printf("%lld ", 1LL << i);
			puts("1");
			ans[M] = 'L';
		}
		for (int i = 0; i < n; i++) {
			if (!z)
				x[i]++;
			for (int j = 0; j < M - 1; j++)
				if (abs(x[i]) & (1LL << j))
					if ((x[i] < 0) ^ !((abs(x[i]) ^ abs(y[i])) & (1LL << (j + 1))))
						ans[j] = 'L', x[i] += 1LL << j;
					else
						ans[j] = 'R', x[i] -= 1LL << j;
				else
					if ((y[i] < 0) ^ !((abs(x[i]) ^ abs(y[i])) & (1LL << (j + 1))))
						ans[j] = 'D', y[i] += 1LL << j;
					else
						ans[j] = 'U', y[i] -= 1LL << j;
			if (abs(x[i]) & (1LL << (M - 1)))
				if (x[i] < 0)
					ans[M - 1] = 'L', x[i] += 1LL << (M - 1);
				else
					ans[M - 1] = 'R', x[i] -= 1LL << (M - 1);
			else
				if (y[i] < 0)
					ans[M - 1] = 'D', y[i] += 1LL << (M - 1);
				else
					ans[M - 1] = 'U', y[i] -= 1LL << (M - 1);
			printf("%s\n", ans);
		}
	}
	return 0;
}