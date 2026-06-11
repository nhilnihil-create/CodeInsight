#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;
	using P = pair<int, pair<int, int>>;
	vector<P> infos(N);
	for (int i = 0; i < N; i++) cin >> infos[i].second.first >> infos[i].second.second >> infos[i].first;
	sort(infos.begin(), infos.end(), greater<P>());

	for (int cx = 0; cx <= 100; cx++) {
		for (int cy = 0; cy <= 100; cy++) {
			int H = infos[0].first + abs(infos[0].second.first - cx) + abs(infos[0].second.second - cy);
			bool IsOK = true;
			for (int i = 1; i < N; i++) {
				int HH = infos[i].first + abs(infos[i].second.first - cx) + abs(infos[i].second.second - cy);
				if (infos[i].first > 0 && H != HH) {
					IsOK = false;
					break;
				}
				if (infos[i].first == 0 && HH < H) {
					IsOK = false;
					break;
				}
			}
			if (IsOK) {
				cout << cx << " " << cy << " " << H << endl;
				return 0;
			}
		}
	}
}
