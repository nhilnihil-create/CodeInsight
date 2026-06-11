#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

using namespace std;

vector<int> diff[2];
set<int> dx[2], dy[2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt", "r", stdin));
	TEST(freopen("output.txt", "w", stdout));
	TEST(freopen("debug.txt", "w", stderr));
	string s;
	int x, y, FT, dir = 0;
	cin >> s >> x >> y;
	FT = s.size();
	for (int i = 0; i < s.size(); i++) if (s[i] == 'T') {
		FT = i;
		break;
	}
	x -= FT;
	for (int i = FT; i < s.size(); i++) {
		if (s[i] == 'T') diff[dir = 1 - dir].push_back(0);
		else diff[dir].back()++;
	}
	dx[1].insert(0);
	for (int i = 0; i < diff[0].size(); i++) {
		dx[i & 1].clear();
		for (auto d : dx[(i - 1) & 1]) {
			dx[i & 1].insert(d + diff[0][i]);
			dx[i & 1].insert(abs(d - diff[0][i]));
		}
	}
	dy[1].insert(0);
	for (int i = 0; i < diff[1].size(); i++) {
		dy[i & 1].clear();
		for (auto d : dy[(i - 1) & 1]) {
			dy[i & 1].insert(d + diff[1][i]);
			dy[i & 1].insert(abs(d - diff[1][i]));
		}
	}
	if (dx[(diff[0].size() - 1) & 1].find(abs(x)) != dx[(diff[0].size() - 1) & 1].end() && dy[(diff[1].size() - 1) & 1].find(abs(y)) != dy[(diff[1].size() - 1) & 1].end()) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
	return 0;
}