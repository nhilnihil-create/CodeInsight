#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
char s[maxn];
int n;

bool judge() {
	for (int i = 1; i < n; ++i)
		if (s[i] != s[n-i]) return true;
	return false;
}

int main() {
	cin >> (s+1);
	for (n = 1; s[n] != '\0'; ++n);
	--n;
	if (s[n] != '0' || s[1] != '1' || judge()) puts("-1");
	else {
		int root = 1;
		printf("1 2\n");
		for (int i = 2; i < n; ++i) {
			printf("%d %d\n", root, i+1);
			if (s[i] == '1') root = i+1;
		}
	}
	return 0;
}