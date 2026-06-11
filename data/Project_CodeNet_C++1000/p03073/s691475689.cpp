#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL)

const int N = 5e5 + 7;
const ll mod = 1e9 + 7;

int diff(string s, string t) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		cnt += s[i] != t[i];
	}
	return cnt;
}


int main() {
	fastIO;
	string s;
	cin >> s;
	string x, y;
	bool b = 0;
	for (int i = 0; i < s.size(); i++) {
		x += '0' + b;
		y += '0' + !b;
		b = !b;
	}
	cout << min(diff(s, x), diff(s, y));
}
