#include <iostream>
#include <cstdio>
using namespace std;

int a, b, m;
int main() {
	cin >> a >> b;
	m = max(a, b);
	cout << (a==b ? 2*a : 2*m-1);
	return 0;
}
