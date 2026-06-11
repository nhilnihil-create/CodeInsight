#include<iostream>
using namespace std;

int main() {
	int r, D, x2000;
	cin >> r >> D >> x2000;

	int x = x2000;
	for (int i = 2001; i <= 2010; i++) {
		x = r * x - D;
		cout << x << endl;
	}

}
