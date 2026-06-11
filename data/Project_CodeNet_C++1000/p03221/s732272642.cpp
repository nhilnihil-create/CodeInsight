#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<map<int, int>> py(n+1);
	vector<vector<int>> numm(m + 1, vector<int>(2));
	int tmp1, tmp2;
	for (int i = 1; i <= m; i++) {
		cin >> tmp1 >> tmp2;
		py[tmp1][tmp2]=0;
		numm[i][0] = tmp1;
		numm[i][1] = tmp2;
	}

	for (int i = 1; i <= n; i++) {
		int counter = 1;
		for (auto itr = py[i].begin(); itr != py[i].end(); itr++) {
			itr->second = counter;
			counter++;
		}
	}

	for (int i = 1; i <= m; i++) {
		cout << std::setfill('0') << std::right << std::setw(6) << numm[i][0] 
			<< std::setfill('0') << std::right << std::setw(6) << py[numm[i][0]][numm[i][1]] << endl;
	}
	return 0;
}