#include <cstdio>
#include <bitset>
using namespace std;
const int SUMC = 4e6 + 5;
int N, A, sum;
bitset<SUMC> dp;
int main() {
	scanf("%d", &N);
	dp[0] = 1;
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A);
		dp |= dp << A;
		sum += A;
	}
	for (int i = (sum + 1) / 2; i <= sum; ++i)
		if (dp[i]) {
			printf("%d\n", i);
			break ;
		}
	return 0;
}