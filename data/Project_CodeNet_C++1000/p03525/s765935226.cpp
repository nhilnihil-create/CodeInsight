#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> C(13);
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		++C[x];
	}
	bool zero = false;
	vector<int> sure = { 0 }, dec;
	for (int i = 0; i <= 12; ++i) {
		int limit = 3 - (i == 0 || i == 12 ? 1 : 0);
		if (C[i] >= limit) {
			zero = true;
		}
		else if (C[i] == limit - 1) {
			sure.push_back(i);
			if (limit == 3) sure.push_back(24 - i);
		}
		else if (C[i] == 1) {
			dec.push_back(i);
		}
	}
	int ans = 0;
	for (int i = 0; i < 1 << dec.size(); ++i) {
		vector<int> result = sure;
		for (int j = 0; j < dec.size(); ++j) {
			if ((i >> j) & 1) {
				result.push_back(dec[j]);
			}
			else {
				result.push_back(24 - dec[j]);
			}
		}
		sort(result.begin(), result.end());
		result.push_back(24);
		int val = 24;
		for (int j = 1; j < result.size(); ++j) {
			val = min(val, result[j] - result[j - 1]);
		}
		ans = max(ans, val);
	}
	cout << (zero ? 0 : ans) << endl;
	return 0;
}