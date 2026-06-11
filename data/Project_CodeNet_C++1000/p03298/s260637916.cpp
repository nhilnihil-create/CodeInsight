#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

long long n, sol;
string s;
unordered_map <string, int> mp;

void f (string t, int flg) {
	string a, b;
	for (int mask=0; mask<(1<<n); mask++) {
		a = "", b = "";
		for (int i=0; i<n; i++) {
			if (mask & (1 << i)) {
				a += t[i];
			} else {
				b += t[i];
			}
		}
		if (flg) mp[a+'.'+b]++; else sol += mp[a+'.'+b];
	}
}

int main () {
	cin >> n >> s;
	f(s.substr(0, n), 1);
	s = s.substr(n, n);
	reverse(s.begin(), s.end());
	f(s, 0);
	cout << sol;
	return 0;
}