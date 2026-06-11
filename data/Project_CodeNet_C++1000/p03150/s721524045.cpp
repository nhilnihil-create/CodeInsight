#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
int main() {
	string s;
	cin >> s;
	int n = s.size();
	string t = "keyence";
	rep(i, 8) {
		string ns = s.substr(0, i) + s.substr(n - 7 + i);
		if (ns == t) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}