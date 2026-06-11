#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	string s, t;
	cin >> s >> t;
	map<char, vector<int>> sm, tm;
	for (int i = 0; i < s.size(); i++) {
		sm[s[i]].push_back(i);
		tm[t[i]].push_back(i);
	}
	vector<string> ss;
	for (auto e : sm) {
		string tmp;
		for (auto f : e.second) {
			tmp.append(" ");
			tmp.append(to_string(f));
		}
		ss.push_back(tmp);
	}
	vector<string> ts;
	for (auto e : tm) {
		string tmp;
		for (auto f : e.second) {
			tmp.append(" ");
			tmp.append(to_string(f));
		}
		ts.push_back(tmp);
	}
	sort(ss.begin(), ss.end());
	sort(ts.begin(), ts.end());

	
	if (ss.size() != ts.size()) {
		cout << "No" << endl;
		return 0;
	}

	for (int i = 0; i < ss.size(); i++) {
		if (ss[i] != ts[i]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}