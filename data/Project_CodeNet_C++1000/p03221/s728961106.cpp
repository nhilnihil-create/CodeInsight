#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>code(m,vector<int>(3));
	for (int i = 0; i < m; i++) {
		code.at(i).at(2) = i;
		cin >> code.at(i).at(0) >> code.at(i).at(1);
	}
	sort(code.begin(), code.end());
	int prefecture = code.at(0).at(0);
	int birth = 0;
	for (int i = 0; i < m; i++) {
		if (prefecture == code.at(i).at(0))birth++;
		else {
			prefecture = code.at(i).at(0);
			birth = 1;
		}
		code.at(i).at(1) = birth;
		swap(code.at(i).at(0), code.at(i).at(2));
		swap(code.at(i).at(1), code.at(i).at(2));
	}
	sort(code.begin(), code.end());
	for (int i = 0; i < m; i++) {
		printf("%06d", code.at(i).at(1));
		printf("%06d", code.at(i).at(2));
		cout << endl;
	}
}
