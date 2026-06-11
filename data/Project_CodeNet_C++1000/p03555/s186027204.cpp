#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	string a, b;
	cin >> a >> b;
	string ans = "NO";
	if (a[0] == b[2] && a[1] == b[1] && a[2] == b[0]) ans = "YES";
	cout << ans << endl;
	return 0;
}
