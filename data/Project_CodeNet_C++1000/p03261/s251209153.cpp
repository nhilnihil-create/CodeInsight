#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
string a[200];
unordered_set <string> s;
int32_t main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	s.insert(a[0]);
	for(int i = 1; i < n; ++i) {
		int b = s.size();
		if (a[i][0] != a[i-1][a[i-1].length()-1]) {
			cout << "No";
			return 0;
		}
		s.insert(a[i]);
		if (b == s.size()) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
}