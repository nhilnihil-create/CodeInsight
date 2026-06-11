#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	string s, t;
	cin >> s >> t;
	int n = s.size();
	vector<int> a(n), b(n);
	map<char, int> sm, tm;
	rep(i, n) {
		if(!sm.count(s[i])) {
			sm[s[i]] = sm.size()+1;
		}
		a[i] = sm[s[i]];
	}
	rep(i, n) {
		if(!tm.count(t[i])) {
			tm[t[i]] = tm.size()+1;
		}
		b[i] = tm[t[i]];
	}
	if(a == b) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}