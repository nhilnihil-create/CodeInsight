#include<iostream>
using namespace std;

int main() {
	int r, D, x;
	cin >> r >> D >> x;

	int FirstNum = r * x - D;

	cout << FirstNum << endl;

	for (int i = 1; i < 10; i++) {
		cout << r * FirstNum - D << endl;
		FirstNum = r * FirstNum - D;
	}

}