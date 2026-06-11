#include<bits/stdc++.h>
using namespace std;

int main() {
	map<int, int> mp;
	for (int i = 0; i < 4; i++) {
		int n;
		cin >> n;
		mp[n]++;
	}
	cout << (mp[1] && mp[9] && mp[7] && mp[4] ? "YES" : "NO") << endl;
	return 0;
}