#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string getRotaion(string s) {
	string tmp_s = "";
	tmp_s += s[s.size() - 1];
	for (int i = 0; i < s.size()-1; i++) {
		tmp_s += s[i];
	}
	return tmp_s;
}


int main() {

	string s, t; cin >> s >> t;
	string tmp_s = s;
	for (int i = 0; i < s.size(); i++) {
		tmp_s = getRotaion(tmp_s);
		if (tmp_s == t) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;
	return 0;
}