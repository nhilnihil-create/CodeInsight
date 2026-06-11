#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main() {
	map<string, int>d;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		d[s]++;
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		d[s]--;
	}

	int ans = 0;
	for (auto&& x : d) {
		ans = max(ans, x.second);
	}
	cout << ans << endl;

	return 0;
}