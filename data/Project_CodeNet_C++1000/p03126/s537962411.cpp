#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> vec(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int b = 0;
			cin >> b;
			vec.at(i).at(b-1)++;
		}
	}
	int result = 0;
	for (int i = 0; i < m; i++) {
		int counter = 0;
		for (int j = 0; j < n; j++) {
			counter += vec.at(j).at(i);
		}
		if (counter == n) result++;
	}
	cout << result << endl;

}