#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int ans, i;
string s;
int main() {
	cin >> s;
	for (i = 0, ans = 700; i < s.size(); i++) ans += (s[i] == 'o' ? 100 : 0);
	cout << ans;
	return 0;
}