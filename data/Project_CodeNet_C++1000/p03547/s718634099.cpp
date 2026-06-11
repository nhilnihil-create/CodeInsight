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
	string x, y;
	cin >> x >> y;
	
	map<string, int> hexa;
	hexa["A"] = 11;
	hexa["B"] = 12;
	hexa["C"] = 13;
	hexa["D"] = 14;
	hexa["E"] = 15;
	hexa["F"] = 16;
	
	int a = hexa[x];
	int b = hexa[y];
	
	if (a > b) {
		cout << ">" << endl;
		return 0;
	}
	else if (a < b) {
		cout << "<" << endl;
		return 0;
	} 
	else {
		cout << "=" << endl;
		return 0;
	}
}