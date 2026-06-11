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

	int D, N;
	cin >> D >> N;

	int ans = 0;

	if (N == 100) {
		N += 1;
		ans = N * pow(100, D);
	}
	else {
		ans = N * pow(100, D);
	}

	cout << ans << endl;

	return 0;
}

