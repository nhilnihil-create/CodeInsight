#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647

int main() {
	int N;
	cin >> N;
	vector<tuple<int, int, int>> vec(N);
	for (int i = 0; i < N - 1; ++i) {
		int c, s, f;
		cin >> c >> s >> f;
		vec[i] = make_tuple(c, s, f);
	}

	for (int i = 0; i < N; ++i) {
		int nowTime = 0;
		for (int j = i; j < N - 1; ++j) {
			int c = get<0>(vec[j]), s = get<1>(vec[j]), f = get<2>(vec[j]);

			while (nowTime < s || nowTime % f != 0)++nowTime;

			nowTime += c;
		}
		cout << nowTime << endl;
	}

	return 0;
}