#include<bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c; cin >> a >> b >> c;
	if(a > b) swap(a, b);
	if(b > c) swap(b, c);
	if(a > b) swap(a, b);
	int res;
	if(a % 2 != b % 2) {
		res = 1;
		a++;
		c++;
	}
	else res = 0;
	cout << (2 * c - a - b) / 2 + res << endl;
	return 0;
}
