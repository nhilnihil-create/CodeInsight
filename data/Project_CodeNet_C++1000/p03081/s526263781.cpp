#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;


//x番目のゴーレムを落とせるかを考える
bool checkLeft(int x, int k, string &s, vector<char> &t, vector<char> &d) {
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i] == s[x])
		{
			x += (d[i] == 'L' ? -1 : 1);
		}

		if (s[x] == '_')
		{
			return x == k;
		}
	}
	return false;
}

int main() {
	int N, Q;
	string s;
	cin >> N >> Q;
	cin >> s;
	vector<char> t(Q);
	vector<vector<char>> d(2, vector<char>(Q));

	s = '_' + s + '_';

	for (int i = 0; i < Q; i++)
	{
		cin >> t[i] >> d[0][i];
		d[1][i] = (d[0][i] == 'L' ? 'R' : 'L');
	}

	int golem = N;
	for (int i = 0; i < 2; i++)
	{
		int lb = 0, m, ub = N + 1;
		while (ub - lb > 1) {
			m = (ub + lb) / 2;
			(checkLeft(m, 0, s, t, d[i]) ? lb : ub) = m;
		}

		golem -= lb;

		reverse(s.begin(), s.end());
	}

	cout << golem << endl;

	return 0;
}