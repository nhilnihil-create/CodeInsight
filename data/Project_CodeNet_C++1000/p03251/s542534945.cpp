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

	int N, M;
	int X, Y;
	cin >> N >> M >> X >> Y;

	int x_max = -100;
	int y_min = 100;

	int v;
	for (int i = 0; i < N; i++) {
		cin >> v;
		if (v > x_max) {
			x_max = v;
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> v;
		if (v < y_min) {
			y_min = v;
		}
	}

	if (max(x_max,X) < min(y_min,Y)) {
		cout << "No War" << endl;
	}
	else {
		cout << "War" << endl;
	}

	return 0;
}

