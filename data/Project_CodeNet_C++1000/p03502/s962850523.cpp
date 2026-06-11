#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int num = n;
	int sum=0;
	while (n != 0) {
		sum = sum + n % 10;
		n = n / 10;
	}

	if (num % sum == 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}