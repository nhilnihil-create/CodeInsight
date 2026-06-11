#include <bits/stdc++.h>
using namespace std;
int ans = 0;
vector<int> t(1<<26);
vector<bool> v(1<<26);
int main() {
	ios_base::sync_with_stdio(0);
	string s;
	cin>>s;
	int q = 0;
	int ans = 0;
	int n = s.size();
	v[0] = 1;
	for(int i = 0; i < n; ++i) {
		q ^= 1<<(s[i]-'a');
		int mi = 1e9;
		if(v[q]) {
			mi = min(mi, t[q]);
		}
		for(int j = 0; j < 26; ++j) {
			q ^= 1<<j;
			if(v[q]) {
				mi = min(mi, t[q]+1);
			}
			q ^= 1<<j;
		}
		if(v[q]) {
			t[q] = min(t[q], mi);
		}
		else {
			t[q] = mi;
			v[q] = 1;
		}
		ans = mi;
	}
	if(q == 0) {
		ans = 1;
	}
	cout<<ans<<'\n';
}
