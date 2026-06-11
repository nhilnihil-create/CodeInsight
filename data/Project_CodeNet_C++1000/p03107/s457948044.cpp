#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	int ans = 0;
	stack<char>cube;
	for (int i = 0; i < s.length(); i++) {
		char t = s.at(i);
		if (cube.size() == 0)cube.push(t);
		else if (cube.top() != t) {
			ans++;
			cube.pop();
		}
		else cube.push(t);
	}
	ans *= 2;
	cout << ans << endl;
}