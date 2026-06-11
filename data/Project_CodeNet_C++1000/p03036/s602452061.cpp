#include <iostream>
using namespace std;
int main() {
	long long R, D, X;
	cin >> R >> D >> X;
	for(int i = 1; i <= 10; ++i) {
		X = R * X - D;
		cout << X << endl;
	}
	return 0;
}