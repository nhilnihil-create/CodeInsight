// In the name of God

#include <bits/stdc++.h>

using namespace std;

map<int,int> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mp[x]++;
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if(mp[x] == 0) {
			cout << "NO";
			exit(0);
		}
		mp[x]--;
	}
	cout << "YES";

	return 0;
}
