#include <iostream>
#include <cstdio>
using namespace std;

int a, b;
int main() {
	cin >> a >> b;
	cout << (b%a ? b-a : a+b);
	return 0;
}
