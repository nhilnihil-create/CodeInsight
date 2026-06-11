#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<map>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<cctype>
using namespace std;


int main() {
	int n;
	cin >> n;
	int c = 0;
	for (int i = 0; i < 4; i++) {
		if (n % 10 == 2)
			c++;
		n = n / 10;
	}
	cout << c << endl;
}