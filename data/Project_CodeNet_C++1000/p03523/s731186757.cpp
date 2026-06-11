/* Not my code */
#include <cstdio>
#include <cstring>
#define N 55
int main(void)
{
	const char *tar = "AKIHABARA";
	char str[N];
	scanf("%s", str);
	int len = strlen(str);
	int i, j = 0;
	for (i = 0; tar[i]; ++i) {
		if (j == len || str[j] != tar[i]) {
			if (tar[i] != 'A') return !printf("NO");
		}
		else ++j;
	}
	printf("%s", j != len ? "NO" : "YES");
}