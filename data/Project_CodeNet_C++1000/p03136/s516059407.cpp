#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> L(N);
	for (int i = 0; i < N; i++) cin >> L[i];

	int long_edge = 0;

	for (int i = 0; i < N; i++) {
		long_edge = max(long_edge, L[i]);
	}

	int sum = 0;
	bool once = true;

	for (int i = 0; i < N; i++) {
		if (L[i] == long_edge && once) {
			once = false;
			continue;
		}
		else sum += L[i];
	}

	if (long_edge < sum) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
