#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
	int n, m;
	cin >> n >> m;
	long ans = (100 * (n - m) + 1900 * m) * (1 << m);
	cout << ans << endl;
}