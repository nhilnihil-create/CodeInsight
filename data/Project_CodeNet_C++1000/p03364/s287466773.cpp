#include <bits/stdc++.h>
using namespace std;
const int N = 300 + 10;
string s[N];
int ans;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int dif = 0; dif < n; dif++) {
		int z = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (s[i][(j + dif) % n] != s[j][(i + dif) % n]) {
					z = 1;
					break;
				}		
			}
		}
		if (!z)
		ans += n;
	}
	cout << ans;
	return 0;
}
