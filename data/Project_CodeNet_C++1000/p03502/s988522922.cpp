#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	int X=0;
	int Y = N;

	for (int i = 0; i < 9; i++) {
		X += N % 10;
		N = N / 10;

	}

	if (Y % X == 0) {
		cout << "Yes" << endl;
		
	}
	else {

		cout << "No" << endl;
	}

}
