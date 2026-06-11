#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int X;
	scanf("%d", &X);
	if (X == 1) {
		printf("1\n");
		return 0;
	}
	int b = 2;
	int ans = 0;
	while (1) {
		int a = b;
		while (1) {
			a *= b;
			if (a <= X) {
				ans = max(ans, a);
				// cout << ans << "\n";
			} else {
				break;
			}
		}
		if (b > 40) {
			break;
		} else {
			b++;
		}
	}
	printf("%d\n", ans);

	return 0;
}
