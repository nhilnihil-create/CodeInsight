#include<stdio.h>
using namespace std;


int main() {
	int n, a, b;
	int sum = 0;
	//scanf_s("%d%d%d", &n, &a, &b);
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++) {
		int j = i; //iの値を操作すると、順番が狂う。
		int remainder = 0;
		while (j > 0) {
			remainder += j % 10;
			j /= 10;
		}
		if (a <= remainder && remainder <= b) {
			sum += i;
		}
	}
	printf("%d", sum);

	return 0;
}
