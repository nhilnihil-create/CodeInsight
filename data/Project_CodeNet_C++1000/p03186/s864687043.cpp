#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	if (c <= a + b + 1) cout << c + b << endl;
	else if (c > a + b + 1)cout << a + b + 1 + b << endl;
}