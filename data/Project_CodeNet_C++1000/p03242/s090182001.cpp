#include <cstdio>

char str[100010];

int main() {
	scanf("%s", str);
	for (int i = 0; str[i]; ++i)
		printf("%c", '1' + '9' - str[i]);
	return 0;
}
