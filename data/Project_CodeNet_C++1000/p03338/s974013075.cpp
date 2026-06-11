#include<bits/stdc++.h>
using namespace std;
int count(string s1, string s2) {
	int n = s1.size();
	int m = s2.size();
	map<char, int> map, ch;
	for (int i=0; i<n; i++) {
		map[s1[i]] = 1;
	}
	int c = 0;
	for (int i=0; i<m; i++) {
		if (map[s2[i]] == 1 && ch[s2[i]] == 0) {
			c++;
			ch[s2[i]] = 1;
		}
	}
	return c;
}
int main () {
	int n;
	string s1, s2, s;
	cin >> n;
	cin >> s;
	int ans = 0;
	for (int i=1; i<n; i++) {
		s1 = s.substr(0, i);
		s2 = s.substr(i, n-i+1);
		ans = max(ans, count(s1, s2));
	}
	cout << ans;
}