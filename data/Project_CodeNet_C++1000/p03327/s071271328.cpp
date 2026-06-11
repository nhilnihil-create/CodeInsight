#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	string third;
	third = "C";
	
	if (n > 999) {
		n -=  999;
		third = "D";
	}
	
	cout << "AB" + third  << endl;
}