#include <bits/stdc++.h>
using namespace std;

int n;
long long ans;
string s;
map < pair < string, string >, long long > m;

signed main () {
	cin >> n >> s;
	for (int i = 0; i < (1 << n); ++i) {
		string red, blue;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) 
				red += s[j];
			else 
				blue += s[j];
		}
		reverse(blue.begin(), blue.end());
		++m[make_pair(red, blue)];
	}
	for (int i = 0; i < (1 << n); ++i) {
		string red, blue;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) 
				red += s[n + j];
			else 
				blue += s[n + j];
		}
		reverse(blue.begin(), blue.end());
		ans += m[make_pair(blue, red)];
	}
	cout << ans << '\n';
}
