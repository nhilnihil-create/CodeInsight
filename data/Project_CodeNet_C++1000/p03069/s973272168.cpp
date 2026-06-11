#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	//cleaning
	while (true) {
		if (s.length()>=2&&s.at(0) == '.')s = s.substr(1);
		else if (s.length() == 1) {
			cout << 0 << endl;
			return 0;
		}
		else break;
	}
	while (true) {
		if (s.length() >= 2 && s.at(s.length() - 1) == '#')s = s.substr(0, s.length() - 1);
		else if (s.length() == 1) {
			cout << 0 << endl;
			return 0;
		}
		else break;
	}
	//cout << s << endl;
	vector<vector<int>>bw(0, vector<int>(2));
	int b = 0;
	int w = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (b == 0 && s.at(i) == '.')w++;
		else if (b >= 1 && s.at(i) == '.') {
			bw.push_back({ b,w });
			b = 0;
			w++;
		}
		else b++;
	}
	bw.push_back({ b,w });
	/*for (int i = 0; i < bw.size(); i++) {
		for (int j = 0; j < 2; j++)cout << " " << bw.at(i).at(j);
		cout << endl;
	}*/
	reverse(bw.begin(), bw.end());
	ll ans = 10000000;
	ll blcnt = 0;
	for (int i = 0; i < bw.size(); i++) {
		if (i == 0) {
			ans = bw.at(i).at(1);
			blcnt += bw.at(i).at(0);
		}
		else {
			ans = min(ans, blcnt + bw.at(i).at(1));
			blcnt += bw.at(i).at(0);
		}
	}
	ans = min(ans, blcnt);
	cout << ans << endl;

}