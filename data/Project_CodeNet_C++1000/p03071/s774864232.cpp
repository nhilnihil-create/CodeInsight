#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	cout << max(a+b, max(a+a-1, b+b-1)) << '\n';
	return 0;
}