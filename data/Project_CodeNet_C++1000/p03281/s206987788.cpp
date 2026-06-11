#include <iostream>
using namespace std;

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 9; i <= n; i+=2) {
		int count = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0)count++;
		}
		if (count == 8)ans++;
	}
	printf("%d", ans);
}