#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int A, P;
	cin >> A >> P;
	P += A * 3;
	P /= 2;
	cout << P << endl;
	return 0;
}