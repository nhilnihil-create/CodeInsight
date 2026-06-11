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
	vector<int> x = { 111,222,333,444,555,666,777,888,999 };

	cin >> N;

	int diff;
	int ans = 0;
	int min = 999;
	for (int i = 0; i < x.size(); i++) {
		diff = abs(N - x[i]);
		if (x[i] >= N && diff < min) {
			min = diff;
			ans = x[i];
		}
	}

	cout << ans << endl;

	return 0;
}

