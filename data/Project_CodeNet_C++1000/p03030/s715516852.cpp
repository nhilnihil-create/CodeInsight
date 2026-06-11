#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<pair<string, int>> pa;
	vector<int> point(n);
	for (int i = 0; i < n; i++) {
		string s;
		int p;
		cin >> s >> p;
		pa.push_back({ s,-p });
		point[i] = -p;
	}
	sort(pa.begin(), pa.end());
	for (int i = 0; i < n; i++) {
		int ans;
		ans = find(point.begin(), point.end(), pa[i].second) - point.begin() + 1;
		cout << ans << endl;
	}	
	return 0;
}