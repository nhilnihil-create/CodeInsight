#include <bits/stdc++.h>
typedef long long ll; 
 
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	int min_a = 1e8;
	int max_a = -min_a;
	int maxi, mini;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		if (max_a < a[i]) {
			max_a = a[i];
			maxi = i;
		}
		if (min_a > a[i]) {
			min_a = a[i];
			mini = i;
		}
	}

	int add = max_a;
	int it = maxi;
	if (max_a < abs(min_a)) {
		add = min_a;
		it = mini;
	}
	vector<vector<int>> res(2);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		res[0].push_back(it + 1);
		res[1].push_back(i + 1);
		cnt++;
	}

	if ((min_a >= 0) || (add > 0)) {
		for (int i = 2; i <= N; i++) {
			res[0].push_back(i - 1);
			res[1].push_back(i);
			cnt++;
		}
	} else if ((max_a <= 0) || (add < 0)) {
		for (int i = N - 1; i >= 1; i--) {
			res[0].push_back(i + 1);
			res[1].push_back(i);
			cnt++;
		}
	}

	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) {
		cout << res[0][i] << " " << res[1][i] << endl;
	} 

	return 0;
}
