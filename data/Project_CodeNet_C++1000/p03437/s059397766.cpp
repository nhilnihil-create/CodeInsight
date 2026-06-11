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
	long long int a, b, c = 1;
	cin >> a >> b;
	if (a % b == 0)
		cout << -1 << endl;
	else {
		while ((c * a) % b == 0) {
			c++;
		}
		cout << c * a << endl;
	}
}
