#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	string ans = "No";
	if (abs(a-c) <= d || (abs(a-b) <= d && abs(b-c) <= d)) ans = "Yes";
	cout << ans << endl;
	return 0;
}
