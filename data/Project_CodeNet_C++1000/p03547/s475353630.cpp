#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	char x, y;
	cin >> x >> y;
	string ans;
	if (x < y)  ans = "<";
	if (x == y)  ans = "=";
	if (x > y)  ans = ">";
	cout << ans << endl;
	return 0;
}
