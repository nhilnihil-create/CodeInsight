//besmellah
#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair <string, string> pii;

map <pii, int> M;

int32_t main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int mask = 0; mask < (1 << n); mask++) {
		string t = "";
		string q = "";
		for (int i = 0; i < n; i++){
			if (mask & (1 << i))
				t += s[i];
			else
				q += s[i];
		}
		M[pii(t, q)] ++;
	}
	int ans = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		string t = "", q = "";
		for (int i = n - 1; i >= 0; i --) {
			if (mask & (1 << i))
				t += s[i + n];
			else
				q += s[i + n];
		}
		ans += M[pii(t, q)];
	}
	cout << ans;
}
