#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <iomanip>

using namespace std;
using ll = long long;

template<typename T> void print(T t) { cout << t << endl; }

int main() {
	int N, Y;
	cin >> N >> Y;
	Y /= 1000;
	for (int m = 0; m <= N; m++) {
		for (int g = 0; g + m <= N; g++) {
			int s = N - g - m;
			if (10 * m + 5 * g + s == Y) {
				cout << m << " " << g << " " << s << endl;
				return 0;
			}
		}
	}

	cout << "-1 -1 -1" << endl;
	return 0;
}