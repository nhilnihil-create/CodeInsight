#include <cstdio>
#include <iostream>

int main(int argc, char const* argv[]) {
	int a, b;
	scanf("%d %d", &a, &b);
	printf(a * b % 2 == 0 ? "Even" : "Odd");
	return 0;
}
