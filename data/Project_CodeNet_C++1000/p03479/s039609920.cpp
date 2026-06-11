#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
using namespace std;

int main() {

	long long X, Y;
	cin >> X >> Y;

	long long ans = 0;
	long long Aval = X;

	while (Aval <= Y) {
		ans += 1;
		Aval *= 2;
	}

	cout << ans << endl;

	return 0;
}

