#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {        
	string s,t;
	cin >> s >> t;
	int n = (int)s.size();
	int m = (int)t.size();
	int index = -1;
	for (int i = 0; i + m - 1< n; ++i) {
		bool d = 1;
		for (int j = i, p = 0; j < i + m; ++j,p++) {
			if (s[j] != '?' && s[j] != t[p]) {
				d = 0;
			}
		}
		if (d) 
			index = i;
	}
	if (index == -1) {
		cout << "UNRESTORABLE";
		return 0;
	}
	for (int i = index, p = 0; i < index + m; ++i,p++) {
		s[i] = t[p];
	}
	for (int i = 0; i < n; ++i) {
		if (s[i] == '?') s[i] = 'a';
	}
	cout << s;
}


