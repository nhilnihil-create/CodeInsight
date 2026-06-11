#include <bits/stdc++.h>
#include <bitset>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
	int a, b, c;
	cin >> a >> b >> c;
	rep(i, 10) {
		c = c * a - b;
		cout << c << endl;
	}
	return 0;
}