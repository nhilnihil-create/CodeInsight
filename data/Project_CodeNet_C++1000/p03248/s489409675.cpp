#include <bits/stdc++.h>
using namespace std;

int n, u;
string s;

signed main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    cin >> s;
    n = s.size();
    if (s.front() == '0' || s.back() == '1')
		cout << "-1\n";
	else {
		for (int i = 0; i < n / 2; ++i) {
			if (s[i] != s[n - i - 2])  {
				cout << "-1\n";
				return 0;
			}
		}
		cout << 1 << ' ' << 2 << '\n';
		for (int i = 1; i < n - 1; i++) {
			cout << u + 1 << ' ' << i + 2 << '\n';
			if (s[i] == '1') 
				u = i + 1;
		}
	}
}
