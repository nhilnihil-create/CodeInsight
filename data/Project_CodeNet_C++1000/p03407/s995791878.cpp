#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib> 
#include <cmath>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	
	int sum = a  + b;
	if (sum >= c) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
}