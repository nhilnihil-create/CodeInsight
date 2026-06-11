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


	int a, b;
	cin >> a >> b;

	int n = b - a - 1;

	int ans = n * (n + 1) / 2;
	ans -= a;

	cout << ans << endl;

	return 0;
}

