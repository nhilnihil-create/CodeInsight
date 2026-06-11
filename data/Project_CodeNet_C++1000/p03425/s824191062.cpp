//ABC089C
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	map<char, int> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s[0] == 'M' ||
				s[0] == 'A' ||
				s[0] == 'R' ||
				s[0] == 'C' ||
				s[0] == 'H') {
			m[s[0]]++;
		}
	}
	string s = "MARCH";
	vector<vector<int>> v = {
		{0, 1, 2},
		{0, 1, 3},
		{0, 1, 4},
		{0, 2, 3},
		{0, 2, 4},
		{0, 3, 4},
		{1, 2, 3},
		{1, 2, 4},
		{1, 3, 4},
		{2, 3, 4},
	};

	long long ans = 0;
	for (auto e : v) {
		ans += (long long)m[s[e[0]]] * m[s[e[1]]] * m[s[e[2]]];
	}
	cout << ans << endl;
}