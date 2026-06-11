#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b&&b == c) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}