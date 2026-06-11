#include <bits/stdc++.h>
using namespace std;

int main() {
	string s,t;
	cin >> s;
	cin >> t;
	vector<int>ss, ts;
	for (size_t i = 0; i < s.length(); i++)ss.push_back(s.at(i) - 97);
	for (size_t i = 0; i < t.length(); i++)ts.push_back(t.at(i) - 97);
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	reverse(t.begin(), t.end());
	int l = min(ss.size(), ts.size());
	for (size_t i = 0; i < l; i++) {
		if (s.at(i) < t.at(i)) {
			cout << "Yes" << endl;
			return 0;
		}
		else if (s.at(i) > t.at(i)) {
			cout << "No" << endl;
			return 0;
		}
	}
	if (ss.size() < ts.size())cout << "Yes" << endl;
	else cout << "No" << endl;
}