#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
using namespace std;
using ll = long long;
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
int main() {
	string s;
	cin >> s;
	int a = 0, b = 0;
	for (auto p : s) {
		if (p == '0')
			a++;
		else
			b++;
	}
	cout << s.size() - abs(a - b) << endl;
	return 0;
}