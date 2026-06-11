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
	int K;
	cin >> K;
	int total = 1;

	for (int i = 0; i < N; i++) {

		if (total <= K) {

			total *= 2;
		}

		else {

			total += K;

		}

	}


	cout << total << endl;

}
