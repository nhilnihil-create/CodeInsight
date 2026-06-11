#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	string s; cin >> s;
	int q; cin >> q;
	while(q--) {
		int k; cin >> k;
		int64_t d = 0, m = 0, dm = 0;
		int64_t dmc = 0;
		for(int i = 0; i < n; ++i) {
			char c = s[i];
			if(c == 'D') {
				++d;
			}
			if(c == 'M') {
				++m;
				dm += d;
			}
			if(c == 'C') {
				dmc += dm;
			}
			if(i - k + 1 >= 0) {
				c = s[i - k + 1];
				if(c == 'D') {
					--d;
					dm -= m;
				}
				if(c == 'M') {
					--m;
				}
			}
			// cerr << s[i] << " " << d << " " << m << " " << dm << " " << dmc << '\n';
		}
		cout << dmc << '\n';
	}
	return 0;
}
