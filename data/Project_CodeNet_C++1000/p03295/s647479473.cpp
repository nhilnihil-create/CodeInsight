#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, m; cin >> n >> m;
	vector<pair<int, int>> pa;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		pa.push_back({ b,a });
	}
	sort(pa.begin(), pa.end());
	int ans = 0;
	for (int i = 0; i < pa.size(); ) {
		int tmpIndex = pa[i].first - 1;
		int cnt = 1;
		ans++;
		for (int j = i + 1; j < pa.size(); j++) {
			if (pa[j].second <= tmpIndex) {
				cnt++;
			}
			else {
				break;
			}
		}
		i += cnt;
	}
	cout << ans << endl;
	return 0;
}