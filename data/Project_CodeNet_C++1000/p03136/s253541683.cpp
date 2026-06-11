#include <stdio.h>
int n, s, a, l[10];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", l + i);
		s += l[i];
	}
	for (int i = 0; i < n; i++) {
		if (l[i] * 2 >= s)a = 1;
	}
	if (a)printf("No\n");
	else printf("Yes\n");
}