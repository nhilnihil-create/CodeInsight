#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include<algorithm>
#include<sstream>
#include<iomanip>


using namespace std;


int main() {
	int n,k;
	cin >> n >> k;
	long long  ans = 0;

	
	if (k % 2 == 0) {
		k /= 2;
		//cout << n / k << endl;

		long long pat1, pat2;
		pat1 = (n / k) / 2;
		pat2 = n / k - pat1;
		ans = pat1 * pat1*pat1 + pat2 * pat2*pat2;
	}
	else {
		long long abc_pat = n / k;
		ans += abc_pat * abc_pat * abc_pat;
	}
	cout << ans << endl;
}