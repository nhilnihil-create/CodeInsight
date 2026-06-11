#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>


using namespace std;



int main() {

	long long int A0, B0, C0, K;

	cin >> A0 >> B0 >> C0 >> K;

	if (K % 2 != 0)
		cout << B0 - A0;
	else
		cout << A0 - B0;
	return 0;

}