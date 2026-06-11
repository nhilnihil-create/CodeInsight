#include <iostream>
#include <cstdio>
using namespace std;

int n, a, x=1, y=1;
int main() {
	cin >> n;
	while(n--) {
		cin >> a;
		x *= 3;
		if(a%2==0) y *= 2;
	}
	cout << x-y;
	return 0;
}