#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", b >= a ? a : a - 1);
	return 0;
}
