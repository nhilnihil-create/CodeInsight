#include <bits/stdc++.h>
using namespace std;
int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	int ans = B + min(C, A + B + 1);
	printf("%d\n", ans);
}
