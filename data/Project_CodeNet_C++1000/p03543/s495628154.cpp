#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	string n;
	cin >> n;
	string ans = "No";
	if ((n[0] == n[1] && n[2] == n[1]) ||
		  (n[1] == n[2] && n[3] == n[2])){
		ans = "Yes";
	}
	cout << ans << endl;
	return 0;
}
