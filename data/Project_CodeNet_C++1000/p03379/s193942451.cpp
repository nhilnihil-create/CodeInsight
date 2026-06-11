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
	vector<int> vec(N);
	for (int i = 0; i < N; ++i)cin >> vec[i];

	vector<int> vec2;
	vec2 = vec;
	sort(vec2.begin(), vec2.end());
	for (int i = 0; i < N; ++i) {
		if (vec[i] < vec2[N / 2] ) {
			cout << vec2[N / 2] << endl;
		}
		else {
			cout << vec2[N / 2 - 1] << endl;
		}
	}

	return 0;
}