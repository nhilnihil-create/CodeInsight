#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	vector<pair<char, int>> a;
	a.emplace_back(make_pair(s[0], 1));
	for (int i = 1; i < s.length(); i++) {
		if (s[i] != s[i - 1]) {
			a.emplace_back(make_pair(s[i], 1));
		} else {
			a[a.size() - 1].second++;
		}
	}

	vector<int> b(a.size() + 2), w(a.size() + 2);
	for (int i = 0; i < a.size(); i++) {
		if (a[i].first == '.') {
			w[i + 1] = a[i].second;
		} else {
			b[i + 1] = a[i].second;
		}
	}
	for (int i = 2; i < a.size() + 2; i++) {
		w[i] += w[i - 1];
		b[i] += b[i - 1];
	}

	int ans = 1010101010;
	for (int i = 1; i <= a.size(); i++) {
		ans = min(ans, b[i - 1] - b[0] + w[a.size() + 1] - w[i]);
	}
	cout << ans << endl;

	return 0;
}