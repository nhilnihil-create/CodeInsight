#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int n; scanf("%d", &n);

	// 各要素Ai - 1, Ai, Ai + 1の3パターン
	int all_case = pow(3, n);

	int all_odd = 1;
	for (int i = 0; i < n; ++i) {
		int a; scanf("%d", &a);

		if ((a & 1) == 0) all_odd *= 2;
	}

	printf("%d\n", all_case - all_odd);

	return 0;
}