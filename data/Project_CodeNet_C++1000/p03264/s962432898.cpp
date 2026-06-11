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

	int K;
	cin >> K;

	int even = K / 2;
	int odd = K / 2 + K % 2;

	cout << even * odd << endl;

	return 0;
}
