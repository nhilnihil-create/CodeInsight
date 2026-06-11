#include <cstdio>
#include <algorithm>
using namespace std;
const int NN = 105;
int N, x, A[NN];
int main() {
	scanf("%d%d", &N, &x);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &A[i]);
	sort(A + 1, A + N + 1);
	for (int i = 1; i <= N; ++i)
		if (x >= A[i])
			x -= A[i];
		else {
			printf("%d\n", i-1);
			return 0;
		}
	if (x == 0)
		printf("%d\n", N);
	else printf("%d\n", N - 1);
	return 0;
}