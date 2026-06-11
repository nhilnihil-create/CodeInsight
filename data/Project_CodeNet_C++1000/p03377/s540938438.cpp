#include <iostream>
#include <cstdio>
using namespace std;

int a, b, x;
int main() {
	cin >> a >> b >> x;
	cout << (a<=x && x<=a+b ? "YES" : "NO");
	return 0;
}
