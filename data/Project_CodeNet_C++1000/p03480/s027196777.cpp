#include <cstdio>
#include <cstring>

int main()
{
	char s[100001];
	scanf("%s", s);
	int l = strlen(s);
	int min = l;
	for (int i = 1; i < l; i++) {
		if (s[i - 1] != s[i]) {
			int t = i > l - i ? i : l - i;
			min = min > t ? t : min;
		}
	}
	printf("%d\n", min);
	return  0;
}
