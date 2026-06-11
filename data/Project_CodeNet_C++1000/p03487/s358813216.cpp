#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {        
	int n;
	cin >> n;
	map<int,int> m;
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		m[c]++;
	}
	int ans = 0;
	for (auto it = m.begin(); it != m.end(); ++it) {
		if (it->second > it->first) {
			ans += it->second - it->first;
		}
		if (it->second < it->first) {
			ans += it->second;
		}
	}
	cout << ans;
}




