#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
 
int main() {
 	string s, t;
	cin >> s >> t;
	map<char, char> d, dd;
	rep(i,26) {
		d['a'+i] = 'X';
		dd['a'+i] = 'X';
	}
	bool can = true;
	rep(i,s.size()) {
		if (d[s[i]] != 'X' && d[s[i]] != t[i]) can = false;
		d[s[i]] = t[i];  
		dd[t[i]] = s[i];
	}

	rep(i,s.size()) {
		if (d[s[i]] != t[i]) can = false;
		if (dd[t[i]] != s[i]) can = false;
	}
	if (can) cout << "Yes" << endl;
	else cout << "No" << endl;
  return 0;
}