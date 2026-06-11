#include "bits/stdc++.h"

using namespace std;

int n, a, b, c;
int ans = INT_MAX;
// 0 = a  ,1 = b, 2 = c, 3 = x
vector<int> l;

void calc(vector<int> choice) {
	int len_a = 0, len_b = 0, len_c = 0;
	int count_a = -1, count_b = -1, count_c = -1;
	for (int i = 0; i < n; ++i) {
		switch (choice[i])
		{
		case 0:len_a += l[i]; count_a++; break;
		case 1:len_b += l[i]; count_b++; break;
		case 2:len_c += l[i]; count_c++; break;

		}
	}
	if (len_a != 0 && len_b != 0 && len_c != 0) {
		int cost = 0;
		cost += count_a * 10;
		cost += count_b * 10;
		cost += count_c * 10;
		cost += abs(a - len_a);
		cost += abs(b - len_b);
		cost += abs(c - len_c);
		ans = min(ans, cost);
	}

}

void dfs(int depth, vector<int> choice) {
	if (depth == n) {
		calc(choice);
	}
	else {
		for (int i = 0; i < 4; ++i) {
			choice.push_back(i);
			dfs(depth + 1, choice);
			choice.pop_back();
		}
	}

}

int main() {

	cin >> n >> a >> b >> c;
	l.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> l[i];
	}
	vector<int> chice;
	dfs(0, chice);

	cout << ans << endl;

	return 0;
}
