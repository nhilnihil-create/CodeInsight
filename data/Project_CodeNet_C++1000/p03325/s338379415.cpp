#include <iostream>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  int a[10010];
  int sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		while (a[i] % 2 == 0) { a[i] /= 2; sum++; }
	}
	printf("%d\n", sum);
	return 0;
}