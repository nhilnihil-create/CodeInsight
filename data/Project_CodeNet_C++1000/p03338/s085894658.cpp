#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	string s; cin >> s;
	const int p = 26;
	int ans = 0;
	for (int i = 1; i <= n - 1; i++) {
		string s_left = s.substr(0, i);
		string s_right = s.substr(i);
		vector<int> leftNum(p, 0);
		vector<int> rightNum(p, 0);
		for (int i = 0; i < s_left.size(); i++) {
			leftNum[s_left[i] - 'a'] = 1;
		}
		for (int i = 0; i < s_right.size(); i++) {
			rightNum[s_right[i] - 'a'] = 1;
		}
		int tmp = 0;
		for (int i = 0; i < p; i++) {
			if (leftNum[i] == 1 && rightNum[i] == 1) tmp++;
		}
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}