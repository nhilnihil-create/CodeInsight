#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
	int A, B;
	int result;
	cin >> A >> B;
	if (A >= 13) {
		result = B;
	} else if (A >= 6) {
		result = B/2;
	} else {
		result = 0;
	}
	cout << result << "\n";
	return 0;
}