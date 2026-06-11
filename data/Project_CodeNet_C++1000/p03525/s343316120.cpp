#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, D[100], cnt[100], ans = 0;

int main() {
	cin >> N; cnt[0]++;
	for (int i = 1; i <= N; i++) { cin >> D[i]; cnt[D[i]]++; }

	for (int i = 0; i < (1 << 13); i++) {
		vector<int>vec;
		for (int j = 0; j <= 12; j++) {
			if (cnt[j] == 0) {

			}
			if (cnt[j] == 1) {
				if ((i / (1 << j)) % 2 == 0) vec.push_back(j);
				else vec.push_back((24 - j) % 24);
			}
			if (cnt[j] == 2) {
				vec.push_back(j);
				vec.push_back((24 - j) % 24);
			}
			if (cnt[j] >= 3) {
				cout << "0" << endl;
				return 0;
			}
		}
		sort(vec.begin(), vec.end());

		int minx = 24;
		for (int j = 0; j < vec.size(); j++) {
			int v1 = vec[j], v2 = vec[(j + 1) % vec.size()]; if (j == vec.size() - 1) v2 += 24;
			minx = min(minx, v2 - v1);
		}
		ans = max(ans, minx);
	}
	cout << ans << endl;
	return 0;
}