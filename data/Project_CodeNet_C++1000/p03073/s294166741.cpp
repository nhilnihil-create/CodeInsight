#include "bits/stdc++.h"
using namespace std;

//40
typedef long long ll;

int main() {
	string s;
	cin >> s;
	int n = (int)s.size();
	string s1 = "";
	string s2 = "";
	int minn1 = 0;
	int minn2 = 0;
	for (int i = 0; i < n; i += 2) {
		if (i + 1 < n) {
			s1 += "10";
			s2 += "01";
		}else {
			s1 += "1";
			s2 += "0";
		}
	}
	for (int i = 0; i < n; ++i) {
		if (s1[i] != s[i]) minn1++;
		if (s2[i] != s[i]) minn2++;
	}
	cout << min(minn1,minn2);
}
