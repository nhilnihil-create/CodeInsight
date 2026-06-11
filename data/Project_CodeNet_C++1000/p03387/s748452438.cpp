#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stack>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
using ll = long long;


int main() {
	int A[3];
	rep(i, 3) cin >> A[i];
	sort(A, A+3);

	int z = 3 * A[2] - (accumulate(A, A+3, 0));
	if (z % 2 == 0) {
		cout << z /2 << endl;
	}
	else {
		cout << (z+3) / 2 << endl;
	}
}