#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1e9+7;
using namespace std;
using ll = long long;

int main() {
	string str;
	int ans = 0;
	cin >> str;
	int n = str.size();
	vector<int> s(n);
	rep(i,n) {
		if (str[i] == 'A' || str[i] == 'C' || str[i] == 'G' || str[i] == 'T') s[i] = 1;
		else s[i] = 0;
	}
	if (n == 1) {
		if (s[0]) cout << 1;
		else cout << 0;
		return 0;
	}
	int count = 0;
	rep(i,n-1) {
		if (s[i] && s[i+1]) count++;
		if (s[i] && !s[i+1]) {
			count++;
			if (ans < count) ans = count;
			count = 0;
		}
		if (i == n - 2 && s[i+1]) {
			count++;
			if (ans < count) ans = count;
		}
	}
	cout << ans;
	return 0;
}
