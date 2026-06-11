#include<iostream>
using namespace std;

int main(void) {
	
	char x[2][3];
	cin >> x[0][0] >> x[0][1] >> x[0][2] >> x[1][0] >> x[1][1] >> x[1][2];
	if (x[0][0] == x[1][2] && x[0][1] == x[1][1] && x[0][2] == x[1][0]) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;

}