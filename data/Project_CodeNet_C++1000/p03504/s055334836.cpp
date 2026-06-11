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
	int32_t N, C;
	scanf("%d%d", &N, &C);

	vector<pair<int32_t, int32_t>> band[30];
	for (int32_t i = 0; i < N; i++) {
		int32_t s, t, c;
		scanf("%d%d%d", &s, &t, &c);
		c--;
		band[c].push_back(make_pair(s, t));
	}

	for (int32_t i = 0; i < C; i++) {
		sort(band[i].begin(), band[i].end());
		// merge continuous band
		int32_t prev_index = 0;
		for (int32_t j = 1; j < (int32_t)band[i].size(); j++) {
			if (band[i][prev_index].second == band[i][j].first) {
				band[i][prev_index].second = band[i][j].second;
				band[i][j].first = band[i][j].second = 0;
			} else
				prev_index = j;
		}

		// append channel switch duration
		for (int32_t j = 0; j < (int32_t)band[i].size(); j++) {
			if (band[i][j].first > 1)
				band[i][j].first--;
		}
	}

	int32_t imos[100002];
	memset(imos, 0, sizeof(imos));
	for (int32_t i = 0; i < C; i++) {
		for (int32_t j = 0; j < (int32_t)band[i].size(); j++) {
			imos[band[i][j].first + 1]++;
			imos[band[i][j].second + 1]--;
		}
	}

	int32_t res = 0;
	for (int32_t i = 1; i < 100002; i++) {
		imos[i] += imos[i - 1];
		res = max(res, imos[i]);
	}

	printf("%d\n", res);

	return 0;
}
