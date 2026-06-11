#include<cstdio>
int a, b, c;
int main() {
	scanf("%d%d%d", &a, &b, &c);
	printf("%d", a == b ? c : a == c ? b : b == c ? a:114514);
}