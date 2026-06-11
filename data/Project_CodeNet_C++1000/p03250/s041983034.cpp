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

	vector<int> val(3, 0);
	cin >> val[0] >> val[1] >> val[2];

	sort(val.begin(), val.end());

	cout << 10 * val[2] + val[1] + val[0] << endl;

	return 0;
}
