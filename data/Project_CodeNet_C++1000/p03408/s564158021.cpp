#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N, M;
	cin >> N;
	map<string, int> s;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		s[str]++;
	}
	cin >> M;
	for (int i = 0; i < M; ++i) {
		string str;
		cin >> str;
		s[str]--;
	}

	int ans = 0;
	for (auto i : s) {
		ans = max(ans, i.second);
	}
	cout << ans << endl;

	return 0;
}
