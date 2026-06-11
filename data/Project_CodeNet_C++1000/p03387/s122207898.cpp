#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c,ans=0,tmp1;
	cin >> a >> b >> c;
	vector<int> n = { a,b,c }, tmp = { a,b,c };
	sort(n.begin(), n.end());
	sort(tmp.begin(), tmp.end());
	ans = n.at(2) - n.at(1);
	tmp.at(0) += ans;
	tmp.at(1) += ans;
	tmp1 = (tmp.at(2) - tmp.at(0)) / 2;
	ans += tmp1;
	tmp.at(0) += tmp1 * 2;
	if (tmp.at(0) == tmp.at(1) && tmp.at(0) == tmp.at(2)) {
		cout << ans << endl;
	}
	else if (tmp.at(0) + 2 == tmp.at(2)) {
		cout << ans + 1 << endl;
	}
	else if (tmp.at(0) + 1 == tmp.at(2)) {
		cout << ans + 2 << endl;
	}
}