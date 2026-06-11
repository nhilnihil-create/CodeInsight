#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define Int int64_t
using ll = long long;

int main() {
	Int x, y;
	cin >> x >> y;

	Int a = x;
	int i = 0;
	while (a <= y) {
		i++;
		a = a * 2;
	}

	cout << i << endl;


}