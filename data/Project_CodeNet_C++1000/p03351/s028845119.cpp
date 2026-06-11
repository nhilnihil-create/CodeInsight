#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf((abs(a - b) <= d && abs(b - c) <= d) || abs(a - c) <= d ? "Yes\n" : "No\n");
	return 0;
}
