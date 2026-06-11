#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<bitset>
using namespace std;

int main() {

	int N;
	cin >> N;

	int x_max = N / 4;
	bool jdg = false;
	for (int x = 0; x <= x_max; x++) {
		if (0 == (N - 4 * x) % 7) {
			jdg = true;
			break;
		}
	}

	if (jdg == true) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}

