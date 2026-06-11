#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	string ans;
	if (a + b > c + d) {
		ans = "Left";
	}
	else if (a + b == c + d) {
		ans = "Balanced";
	}
	else{
		ans = "Right";
	}
	cout << ans << endl;
	return 0;
}
