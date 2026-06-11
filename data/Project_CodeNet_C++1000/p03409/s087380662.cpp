#include<iostream>
#include<vector>
#include<algorithm>
int main() {
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>>r(n), b(n);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			if (i)std::cin >> b[j].first >> b[j].second;
			else std::cin >> r[j].first >> r[j].second;
		}
	}
	std::sort(r.begin(), r.end(), [](const auto a, const auto b) {return a.second > b.second; });
	std::sort(b.begin(), b.end(), [](const auto a, const auto b) {return a.first < b.first; });
	std::vector<bool>flags(n, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (r[i].first < b[j].first&&r[i].second < b[j].second && !flags[j]) {
				flags[j] = true;
				break;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)ans += flags[i];
	printf("%d\n", ans);
}