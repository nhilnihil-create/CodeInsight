#include <cstdio>
#include <cstring>

char str[500010];

int main() {
	int ans = 0;
	scanf("%s", str);
	int sp1 = 0, sp2 = strlen(str) - 1;
	while (sp1 < sp2) {
		int t1 = 0, t2 = 0;
		while (str[sp1] == 'x') ++t1, ++sp1;
		while (str[sp2] == 'x') ++t2, --sp2;
		if (str[sp1] != str[sp2]) {
			puts("-1");
			return 0;
		}
		ans += t1 > t2 ? t1 - t2 : t2 - t1;
		++sp1, --sp2;
	}
	printf("%d", ans);
	return 0;
}
