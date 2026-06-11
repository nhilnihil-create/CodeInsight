#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; cin >> s;
	int a = 0;
	int b = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') a++;
		if (s[i] == '1') b++;
	}
	cout << 2 * min(a, b) << endl;
	return 0;
}
