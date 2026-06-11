#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int N, X[1 << 18], Y[1 << 18], T[1 << 18];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> T[i] >> X[i] >> Y[i];
	for (int i = 1; i <= N; i++) {
		int s = abs(X[i] - X[i - 1]) + abs(Y[i] - Y[i - 1]);
		if ((s + (T[i] - T[i - 1])) % 2 == 1 || (T[i] - T[i - 1]) < s) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}