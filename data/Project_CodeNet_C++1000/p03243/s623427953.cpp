#include <iostream>
#include <cstdio>
using namespace std;

int n;
bool flag;
int a[15] = { 0, 111, 222, 333, 444, 555, 666, 777, 888, 999 };

int main() {
	scanf("%d", &n);
	flag = n > a[n / 100];
	printf("%d\n", a[n / 100 + flag]);
	return 0;
}