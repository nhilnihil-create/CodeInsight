#include <iostream>
#include <cstdio>
using namespace std;

int a, b, c, d;
int main() {
	cin >> a >> b >> c >> d;
	a += b;
	c += d;
	cout << (a==c ? "Balanced" : a>c ? "Left" : "Right");
	return 0;
}
