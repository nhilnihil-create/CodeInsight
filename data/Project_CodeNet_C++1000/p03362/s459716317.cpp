#include <iostream>
#include <vector>
using namespace std;
int main() {
	int a[55555];
	fill(a, a + 55555, 0);
	vector<int> b;
	for (int i = 2; i < 55555; i++) {
		if (a[i] == 0) {
			if (i % 5 == 1) b.push_back(i);
			for (int j = i * 2; j < 55555; j += i) a[j] = 1;
		}
	}
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		if (i) printf(" ");
		printf("%d", b[i]);
	}
	printf("\n");
	return 0;
}