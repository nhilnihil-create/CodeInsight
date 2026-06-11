#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	int n, j, sum1, min = 1000, sum2, k;
	cin >> n;
	for (int i = 1; i < n; i++) {
		sum1 = 0;
		sum2 = 0;
		j = i;
		while (j > 0) {
			sum1 += j % 10;
			j /= 10;
		}
		k = n - i;
		while (k > 0) {
			sum2 += k % 10;
			k /= 10;
		}
		if (min > sum1+sum2) {
			min = sum1+sum2;
		}
	}
	cout << min << endl;
	return 0;
}