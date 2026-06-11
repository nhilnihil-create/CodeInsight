#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
	string s, t;
	cin >> s >> t;
	int n = s.size();
	int m = t.size();
	sort(s.begin(), s.end());
	sort(t.rbegin(), t.rend());
	s = s.substr(0, n);
	t = t.substr(0, n);
	if (s == t && n < m)
		cout << "Yes" << endl;
	else if (s < t)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}