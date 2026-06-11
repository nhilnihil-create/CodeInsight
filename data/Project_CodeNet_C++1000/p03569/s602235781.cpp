#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

char str[N];

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> str;
	int len = strlen(str);
	
	vector<char> buf;
	vector<int> pos;
	for (int i = 0; i < len; i++) if (str[i] != 'x') buf.push_back(str[i]), pos.push_back(i);
	for (int i = 0; i < buf.size(); i++) if (buf[i] != buf[buf.size() - 1 - i]) {
		cout << "-1\n";
		return 0;
	}
	if (buf.size() == 0) {
		cout << "0\n";
		return 0;
	}
	int r = pos[buf.size() / 2];
	int l = pos[buf.size() - 1 - buf.size() / 2];
	int ans = 0;
	while (l >= 0 && r < len) {
		if (str[l] == str[r]) l--, r++;
		else {
			if (str[l] == 'x') ans++, l--;
			else ans++, r++;
		}
	}
	ans += max(l + 1, len - r);
	cout << ans << "\n";
	
	return 0;
}
