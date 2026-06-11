#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) x.begin(), x.end()
#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	if(s.size() == a + b + 1) {
		if(s[a] == '-') {
			int cnt = 0;
			for(int i = 0; i < s.size(); i++) {
				if(int(s[i]) - 48 < 0 || int(s[i]) - 48 > 9) {
					if(i != a) {
						cnt++;
					}
				}
			}
			if(cnt == 0) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		} else {
			cout << "No\n";
		}
	} else {
		cout << "No\n";
	}
}
