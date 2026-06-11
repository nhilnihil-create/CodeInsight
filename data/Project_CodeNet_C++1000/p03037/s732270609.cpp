#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <climits>

#define PI 3.14159265359

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> L(M);
	vector<int> R(M);

	for (int i = 0; i < M; ++i) {
		cin >> L[i] >> R[i];
	}

	int maxNo = 100000;
	int minNo = 0;

	for (int i = 0; i < M; ++i) {
		minNo = max(minNo, L[i]);
		maxNo = min(maxNo, R[i]);
	}

	int ans = maxNo - minNo;
	if (ans < 0) {
		cout << 0 << endl;
	}
	else {
		cout << (maxNo - minNo) + 1 << endl;
	}
	return 0;
}