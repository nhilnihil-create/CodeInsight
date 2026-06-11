#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <cmath>
#include <map>
using namespace std;
#pragma warning (disable: 4996)

long long N, K, a[100009], b[100009]; vector<long long>F;

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> a[i] >> b[i];
	long long cx = K + 1;
	while (cx > 0) { F.push_back(cx - 1); cx -= (cx&-cx); }

	long long maxn = 0;
	for (int i = 0; i < F.size(); i++) {
		long long sum = 0;
		for (int j = 0; j < N; j++) {
			if ((a[j] | F[i]) == F[i]) sum += b[j];
		}
		maxn = max(maxn, sum);
	}
	cout << maxn << endl;
	return 0;
}