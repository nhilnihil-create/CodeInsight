#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
int main() {
	int  a, b, c,x,y;
	cin >> a >> b >> c >> x >> y;
	if (2 * c > a + b) {
		cout << a * x + b * y;
	}
	else {
		int d = min(x, y);
		int e = max(x, y);
		if (x > y) {
			cout << min(e*c*2,d * 2 * c + (e - d) * a);
		}
		else {
			cout << min(e*c*2,d * 2 * c + (e - d) * b);
		}
	}
}
