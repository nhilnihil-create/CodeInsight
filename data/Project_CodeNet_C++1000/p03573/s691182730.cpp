#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib> 
#include <cmath>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	
	if (a == b) {
		cout << c << endl;
		return 0;
	}
	else if (b == c) {
		cout << a << endl;
		return 0;
	} else if (a == c) {
		cout << b << endl;
		return 0;
	}
}