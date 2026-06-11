#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
	int n, m;
	long long sum = 0;
	cin >> n >> m;
	vector<pair<int, int>> dr(n);

	rep(i, n) {
		int ai, bi;
		cin >> ai >> bi;
		dr[i] = make_pair(ai, bi);
	}
	sort(dr.begin(), dr.end());
	int j = 0;
	rep(i, m) {
		sum += dr[j].first;
		dr[j].second--;
		if (dr[j].second == 0) {
			j++;
		}
	}
	cout << sum << endl;
	return 0;
}