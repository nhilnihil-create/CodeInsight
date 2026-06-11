#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x, y; cin >> x >> y;
	vector<string>v(x);
	for (string& i : v) cin >> i;
	for (int i = 0 ; i < x ; ++i)
		for (int j = 0; j < y; ++j) 
			if (v[i][j] == '.') {
				int cnt = 0;
				if (j + 1 < y && v[i][j + 1] == '#') ++cnt;
				if (j - 1 >= 0 && v[i][j - 1] == '#') ++cnt;
				if (i + 1 < x && v[i + 1][j] == '#') ++cnt;
				if (i + 1 < x && j + 1 < y && v[i + 1][j + 1] == '#') ++cnt;
				if (i + 1 < x && j - 1 >= 0 && v[i + 1][j - 1] == '#') ++cnt;
				if (i - 1 >= 0 && v[i - 1][j] == '#') ++cnt;
				if (i - 1 >= 0 && j - 1 >= 0 && v[i - 1][j - 1] == '#') ++cnt;
				if (i - 1 >= 0 && j + 1 < y && v[i - 1][j + 1] == '#') ++cnt;
				v[i][j] = cnt + '0';
			}
	for (auto i : v) {
		for (auto j : i) cout << j;
		cout << "\n";
	}
	return 0;
}

// 