#include<iostream>
#include<string>
#include<algorithm>	
#include<cmath>
using namespace std;
int main() {
	int n, d = 0; string a, b, c; cin >> n >> a >> b >> c;
	for (int h = 0; h < n; h++) {
		if (a[h] != b[h] && a[h] != c[h] && b[h] != c[h]) {
			d++; d++;
		}
		else if (a[h] == b[h] && a[h] == c[h] && b[h] == c[h]) {
			d == d;
		}
		else {
			d++;
		}
	}
	cout << d << endl;
	cin >> n;
}