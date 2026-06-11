#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if(abs(a - c) <= d)
		cout << "Yes";
	else {
		if(abs(a - b) <= d && abs(b - c) <= d)
			cout << "Yes";
		else
			cout << "No";
	}
	return 0;
}
