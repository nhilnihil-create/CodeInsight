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

#include <inttypes.h>
using namespace std;

int main()
{
	int32_t N;
	scanf("%d", &N);

	int32_t t[101];
	int32_t T = 0;
	for (int32_t i = 0; i < N; i++) {
		scanf("%d", &t[i]);
		T += t[i];
	}

	int32_t v[101];
	for (int32_t i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}

	double max_v[40001];
	int32_t max_v_index = 0;
	for (int32_t i = 0; i < N; i++) {
		for (int32_t j = 0; j < 2 * t[i]; j++) {
			if (i > 0 && j == 0)
				max_v[max_v_index++] = min(v[i - 1], v[i]);
			else
				max_v[max_v_index++] = v[i];
		}
	}

	max_v[0] = 0;
	max_v[2 * T] = 0;

	for (int32_t i = 1; i < 2 * T + 1; i++)
		max_v[i] = min(max_v[i], max_v[i - 1] + 0.5);
	for (int32_t i = 2 * T - 1; i >= 0 ; i--)
		max_v[i] = min(max_v[i], max_v[i + 1] + 0.5);

	double res = 0;
	for (int32_t i = 0; i < 2 * T; i++) {
		res += min(max_v[i], max_v[i + 1]) * 0.5;
		if (max_v[i] != max_v[i + 1])
			res += 0.5 * 0.5 / 2;
	}

	printf("%.17f\n", res);

	return 0;
}
