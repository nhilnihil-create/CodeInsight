#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stdlib.h>
#define ll long long
#define MOD_P 1000000007
using namespace std;

int main()
{
	int d[5];
	int k;

	for (int i = 0; i < 5; i++) {
		cin >> d[i];
	}
	cin >> k;

	if (d[4] - d[0] <= k) {
		printf("Yay!");
	} else {
		printf(":(");
	}

	return 0;
}