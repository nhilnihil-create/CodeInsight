#include <iostream>
#include<string>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
using namespace std;
int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	vector<int> k(m);
	vector<vector<int>> s(m, vector<int>(n));
	vector<int> p(m);
	for (int i = 0; i < m; i++) {
		cin >> k[i];
		for (int j = 0; j < k[i]; j++) {
			cin >> s[i][j];
			s[i][j]--;
		}
	}
	for (int i = 0; i < m; i++)
		cin >> p[i];

	for (int i = 0; i < (1 << n); i++) {
		int countright = 0;
		for (int j = 0; j < m; j++) {
			int countswitch = 0;
			for (int l = 0; l < k[j]; l++) {
				if ((i >> (s[j][l])) & 1) {
					countswitch++;
				}
			}
				if (countswitch % 2 == p[j])
					countright++;
		}
		if (countright == m) {
			ans++;
		}
	}
	cout << ans;
}
