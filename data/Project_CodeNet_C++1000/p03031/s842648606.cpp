#include <bits/stdc++.h>
using namespace std;
long long mypow(long long x, long long y)
{
	long long result = 1;
	while (y != 0) {
		if (y%2 != 0) {
			result *= x;
			y -= 1;
		}	
		x *= x;
		y /= 2;
	}
	return result;
}
int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> ss(m);
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int s;
			cin >> s;
			ss[i].push_back(s);
		}
	}
	vector<int> p(m);
	for (int i = 0; i < m; i++)
		cin >> p[i];


	int ans = 0;
	for (uint32_t i = 0; i < mypow(2, n); i++) {
		vector<bool> s(n);
		for (int j = 0; j < n; j++) {
			if (((i>>j)&1) == 1)
				s[j] = true;
			else
				s[j] = false;
		}
		int l_count = 0;
		for (int j = 0; j < m; j++) {
			int s_count = 0;
			for (auto e : ss[j]) {
				if (s[e-1])
					s_count++;
			}
			if (s_count%2 == p[j])
				l_count++;
			else
				break;
		}
		if (l_count == m) {
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}