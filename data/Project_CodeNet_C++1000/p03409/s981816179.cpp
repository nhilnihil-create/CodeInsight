#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> red(N, { 0,0 });
	vector<pair<int, int>> blue(N, { 0,0 });
	for (int i = 0; i < N; i++) cin >> red[i].first >> red[i].second;
	for (int i = 0; i < N; i++) cin >> blue[i].first >> blue[i].second;
	auto lambda1 = [](auto const& a, auto const& b) {return max(a.first, a.second) > max(b.first, b.second); };
	auto lambda2 = [](auto const& a, auto const& b) {return min(a.first, a.second) < min(b.first, b.second); };
	sort(red.begin(), red.end(), lambda1);
	sort(blue.begin(), blue.end(), lambda2);

	vector<int> IsUsed(N, 0);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (IsUsed[j] == 1) continue;
			if (red[i].first < blue[j].first && red[i].second < blue[j].second) {
				ans++;
				IsUsed[j] = 1;
				break;
			}
		}
	}
	cout << ans << endl;

}