#include<bits/stdc++.h>
using namespace std;

const int N = 100009;
int T, n, m, a[N], ans, sum, res;
char s[N];

int main() {
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	if (s[1] == '0' || s[len] == '1') return puts("-1"), 0;
	for (int i = 2; i < len; ++ i) if (s[i] + s[len - i] - 96 == 1) return puts("-1"), 0;
	int root = 1;
	for (int i = 2; i <= len; ++ i) {
		printf("%d %d\n", root, i);
		if (s[i - 1] == '1') root = i;
	}
	return 0;
}
