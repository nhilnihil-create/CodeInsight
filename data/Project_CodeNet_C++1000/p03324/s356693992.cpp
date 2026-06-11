#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <climits>

using namespace std;



int main() {
	int d, n;
	cin >> d >>n;

	int ans;

	if (n != 100) {
		ans = n * pow(100, d);
	}
	else {
		ans = n * pow(100, d)+1* pow(100, d);
	}

	cout << ans << endl;

	return 0;
}