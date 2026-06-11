#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
const ll MOD = 1000000007;
pair<int, int> a[10], b[10];
int main() {
	int a, b;
	cin >> a >> b;
	a = a * 3 + b;
	cout << a / 2 << endl;
	return 0;
}