#include <iostream>
#include <cstdio>
using namespace std;

int n, mn, x[200005], y;
string s;
int main() {
	int i;
	cin >> n >> s;
	s = "-" + s;
	for(i=1; i<=n; i++) x[i] = x[i-1] + (s[i]=='#');
	mn = x[n];
	for(i=n; i; i--) {
		y += s[i]=='.';
		mn = min(mn, y + x[i-1]);
	}
	cout << mn;
	return 0;
}