#include <iostream>
#include <cstdio>
using namespace std;

int a, b, c;
int main() {
	cin >> a >> b >> c;
	cout << (a==b && b==c ? "Yes" : "No");
	return 0;
}
