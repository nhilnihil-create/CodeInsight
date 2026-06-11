#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include<math.h>
#include<bitset>
using namespace std;

int main() {
	int n; cin >> n;
	int x[n], y[n];
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		y[i] = x[i];
	}
	sort(y, y + n);
	int middle = y[(n / 2) - 1];//左側
	for (int i = 0; i < n; i++) {
		if (x[i] <= middle)cout << y[n / 2] << endl;
		else cout << middle << endl;
	}
}