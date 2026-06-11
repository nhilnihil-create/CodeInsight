#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>pri(0, vector<int>(2));
	int i = 1;
	while (i <= sqrt(m)) {
		if (m % i == 0) {
			pri.push_back({ i,m / i });
			pri.push_back({ m / i,i });
		}
		i++;
	}
	sort(pri.begin(), pri.end());
	int pos;
	for (int i = 0; i < pri.size(); i++) {
		if (pri.at(i).at(0) >= n) {
			pos = pri.at(i).at(1);
			break;
		}
	}
	cout << pos << endl;
}