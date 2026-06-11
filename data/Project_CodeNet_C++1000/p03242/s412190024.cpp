#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < 3; i++) {
		if (s.at(i) == '1')cout << 9;
		else if (s.at(i) == '9')cout << 1;
		else cout << s.at(i);
	}
	cout << endl;
}