#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include<numeric>
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0])
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

using namespace std;
typedef long long ll;



int main(void) {
	int c[3][3];
	int x[3],y[3];

	rep(i, 3) {
		rep(j, 3) {
			cin >> c[i][j];
		}
	}
	x[0] = 0;
	rep(i, 3) {
		y[i] = c[0][i] - x[0];
	}
	rep(i, 3) {
		x[i] = c[i][0] - y[0];
	}

	bool good = true;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (x[i] + y[j] != c[i][j]) {
				good = false;
			}
		}
	}
	if (good == 1) {
		cout << "Yes";
	}
	else
		cout << "No";




	return 0;
}
