#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	int D = B / A;
	if (D > C) cout << C << endl;
	else cout << D << endl;
	return 0;
}