#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	string s; cin >> s;
	string t=s;
	reverse(all(t));
	string x;
	int i = 0, j = 0, ans = 0;
	while (i <= s.size() && j <= t.size()) {
		char S = s[i], T = t[j];
		if (S==T) {
			i++;
			j++;
		} else if (S=='x' && T!='x') {
			i++;
			ans++;
		} else if (S!='x' && T=='x') {
			j++;
			ans++;
		} else {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans/2 << endl;
}