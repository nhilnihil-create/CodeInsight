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
	int N, K;
	cin >> N >> K;
	double ans = 0;
	for (int n = 1; n <= N; n++) {
		double pn = 1.0 / N;
		for (int k = n; k < K; k *= 2) pn /= 2;
		ans += pn;
	}
	cout << fixed << setprecision(15);
	print(ans);
}

