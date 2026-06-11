#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	string S;
	cin >> S;
	string ans;
	string date = "";
	date = string(1, S[0]) + string(1, S[1]) + string(1, S[2]) + string(1, S[3]) + string(1, S[5]) + string(1, S[6]) + string(1, S[8]) + string(1, S[9]);
	if (date <= "20190430") {
		ans = "Heisei";
	}
	else {
		ans = "TBD";
	}
	cout << ans << endl;
	return 0;
}
