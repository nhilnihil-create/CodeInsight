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

	long long N, M;
	cin >> N >> M;

	long long ans = pow((long long)2, min((long long)5, M)) * (100 * (N - M) + 1900 * M);

	cout << ans << endl;

	return 0;
}