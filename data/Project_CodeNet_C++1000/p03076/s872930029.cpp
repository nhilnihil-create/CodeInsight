#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>


using namespace std;



int main() {

	double PU[5];
	int P[5], key = 0, tmp = 10, D, sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> P[i];
		PU[i] = ceil((double)P[i] / 10) * 10;
		D = P[i] % 10;
		if (tmp > D && D != 0) {
			key = i;
			tmp = D;
		}
	}
	
	for (int i = 0; i < 5; i++) {
		if (i == key) {
			sum += P[i];
		}
		else {
			sum += PU[i];
		}
	}

	cout << sum;

	return 0;

}