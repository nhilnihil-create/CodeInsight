#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ma = 0;
	for (int i = 1; i < n; i++) {
		string l, r;
		l = s.substr(0, i);
		r = s.substr(i);
		set<char>ls, rs;
		for (int i = 0; i < l.length(); i++)ls.insert(l.at(i));
		for (int i = 0; i < r.length(); i++)rs.insert(r.at(i));
		vector<char>as;
		set_intersection(ls.begin(), ls.end(), rs.begin(), rs.end(), back_inserter(as));
		int x = as.size();
		ma = max(ma, x);
	}
	cout << ma << endl;
}