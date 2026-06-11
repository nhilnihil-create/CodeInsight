#include<bits/stdc++.h>
using namespace std;

int n, L, cnt, tmp, e[80][3];

int main() {
	scanf("%d", &L);
	tmp = L;
	while (tmp) tmp /= 2, n++;
	for (int i = 1; i < n; i++) {
		e[++cnt][0] = i; e[cnt][1] = i + 1; e[cnt][2] = 1 << i - 1;
		e[++cnt][0] = i; e[cnt][1] = i + 1; e[cnt][2] = 0;
	}
	tmp = 1 << n - 1;
	for (int i = n - 1; i >= 1; i--) {
		if (L & (1 << i - 1)) {
			e[++cnt][0] = i; e[cnt][1] = n; e[cnt][2] = tmp;
			tmp += 1 << i - 1;
		}
	}
	printf("%d %d\n", n, cnt);
	for (int i = 1; i <= cnt; i++)
		printf("%d %d %d\n", e[i][0], e[i][1], e[i][2]);
	return 0;
}