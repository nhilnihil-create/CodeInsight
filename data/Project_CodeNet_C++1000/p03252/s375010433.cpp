#include <bits/stdc++.h>
using namespace std;
int main() {
	string s, t;
	cin >> s;
	cin >> t;

	vector<char> alpha = { 'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j','k','l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't','u', 'v', 'w', 'x', 'y', 'z' };
	vector<vector<int>> s_pos(26, vector<int>(0));
	vector<vector<int>> t_pos(26, vector<int>(0));

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < s.length(); j++) {
			if (alpha.at(i) == s.at(j)) {
				s_pos.at(i).push_back(j);
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < t.length(); j++) {
			if (alpha.at(i) == t.at(j)) {
				t_pos.at(i).push_back(j);
			}
		}
	}
	sort(s_pos.begin(), s_pos.end());
	sort(t_pos.begin(), t_pos.end());
	if (s_pos == t_pos) { 
		cout << "Yes"; }
	else { cout << "No"; }
}