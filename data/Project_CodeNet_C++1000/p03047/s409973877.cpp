#include <iostream>
#include<vector>
#include<map>
#include<string>
#include<stdio.h>
#include<math.h>
#include <algorithm>

using namespace std;

int main(void) {

	int a, b;

	cin >> a >> b;
	int sum = 0;

	for (int i = 1; i < a+1; i++) {
		if (a >= i + b - 1) sum++;
	}

	cout << sum << endl;

	return 0;
}
