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

	long T, X;
	cin >> T >> X;

	double ans = 0.0;
	ans = (double)T / (double)X;

	cout << fixed;
	cout << setprecision(6) << ans << endl;
	
	return 0;
}
