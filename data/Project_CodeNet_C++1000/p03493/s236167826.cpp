#include <cstdio>
#include <iostream>

int main(int argc, char const* argv[]) {
	char s[3];
	int ans = 0;
	for (int i = 0; i < 3; i++) {
		scanf("%c", &s[i]);
		if (s[i] == '1') {
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}
