#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	string s;
	cin >> s;
	int c_0 = 0, c_1 = 0;
	int ans = 0;
	rep(i, s.size()){
		if (s[i] == '0') c_0++;
		if (s[i] == '1') c_1++;
	}
	ans = min(c_0, c_1);
	ans *= 2;
	cout << ans << endl;
	return 0;
}
