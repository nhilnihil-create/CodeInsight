// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s, t;
	cin >> s >> t;

	if(t.length() > s.length()) {
		cout << "UNRESTORABLE";
		exit(0);
	}

	string k = s;
	for(int i = 0; i < k.length(); i++) {
		if(k[i] == '?') k[i] = 'a';
	}
	
	int pos = -1;
	for(int i = k.length() - 1; i >= 0; i--) {
		if(i + t.length() - 1 >= k.length()) continue;
		bool f = true;
		for(int j = i; j < i + t.length(); j++) {
			if( k[j] != t[j - i] ) {
				f = false;
				break;
			}
		}
		if(f) {
			pos = i;
			break;
		}
	}

	if(pos != -1) {
		cout << k;
		exit(0);
	}

	for(int i = s.length() - 1; i >= 0; i--) {
		if(i + t.length() - 1 >= s.length()) continue;
		bool f = true;
		for(int j = i; j < i + t.length(); j++) {
			if(s[j] != '?' && s[j] != t[j - i]) {
				f = false;
				break;
			}
		}
		if(f) {
			pos = i;
			break;
		}
	}

	if(pos != -1) {
		for(int i = pos; i < pos + t.length(); i++) {
			s[i] = t[i - pos];
		}
		for(int i = 0; i < s.length(); i++) {
			if(s[i] == '?') s[i] = 'a';
		}
		cout << s;
		exit(0);
	}

	cout << "UNRESTORABLE"; 


	return 0;
}
