#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>

using namespace std;
typedef long long ll;
const int MOD = 1000000007;
#define MAX_N (110)

int main()
{
	int N;
	scanf("%d", &N);

	int factors[MAX_N][MAX_N];
	memset(factors, 0, sizeof(factors));
	for (int i = 2; i <= 100; i++) {
		for (int j = 2; j <= 100; j++) {
			factors[i][j] = factors[i - 1][j];
		}

		int num = i;
		for (int j = 2; j <= 100; j++) {
			while (num % j == 0) {
				factors[i][j]++;
				num /= j;
			}
		}
	}

	int cnt_74 = 0;
	int cnt_24 = 0;
	int cnt_14 = 0;
	int cnt_4 = 0;
	int cnt_2 = 0;
	for (int j = 2; j <= N; j++) {
		if (factors[N][j] >= 74)
			cnt_74++;
		if (factors[N][j] >= 24)
			cnt_24++;
		if (factors[N][j] >= 14)
			cnt_14++;
		if (factors[N][j] >= 4)
			cnt_4++;
		if (factors[N][j] >= 2)
			cnt_2++;
	}

	int res = 0;
	// p0^74
	res += cnt_74;
	// p0^24 * p1^2
	if (cnt_2 - 1 > 0)
		res += cnt_24 * (cnt_2 - 1);

	// p0^14 * p1^4
	if (cnt_4 - 1 > 0)
		res += cnt_14 * (cnt_4 - 1);

	// p0^4 * p1^4 * p2^2
	if (cnt_4 - 1 > 0 && cnt_2 - 2 > 0)
		res += cnt_4 * (cnt_4 - 1) * (cnt_2 - 2) / 2;

	printf("%d\n", res);

	return 0;
}
