#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
#include<sstream>
using namespace std;

int main() {

	long long N;
	cin >> N;

	vector<long long> val(100001, 0);
	long long a;
	long long ans = 0;
	for (long long i = 0; i < N; i++) {
		cin >> a;
		if (a > 100000) {
			ans += 1;
		}
		else {
			val[a] += 1;
		}
	}

	for (long long i = 0; i < val.size(); i++) {
		if (val[i] >= i) {
			ans += val[i] - i;
		}
		else {
			ans += val[i];
		}
	}

	cout << ans << endl;

	return 0;
}