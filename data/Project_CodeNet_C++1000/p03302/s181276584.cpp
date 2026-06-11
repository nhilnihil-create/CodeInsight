#include <bits/stdc++.h>
const long long MOD = 1e9+7;
using namespace std;
#define ll long long
#define ar array

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a,b;
	cin >> a >> b;

	if (a+b==15) {
		cout << '+' << endl;
	} else if (a*b==15) {
		cout << '*' << endl;
	} else {
		cout << 'x' << endl;
	}
	return 0;
}
