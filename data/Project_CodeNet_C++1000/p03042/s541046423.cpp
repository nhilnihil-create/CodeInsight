#include<iostream>
using namespace std;
int main() {
	int S;
	cin >> S;
	int H = S / 100;
	int U = S - H * 100;
	if ((U==0 || U>12)&&(H==0 || H>12)) {
		cout << "NA" << endl;
	}
	else if (U == 0 || U > 12) {
		cout << "MMYY" << endl;
	}
	else if (H == 0 || H > 12) {
		cout << "YYMM" << endl;
	}
	else {
		cout << "AMBIGUOUS" << endl;
	}
	return 0;
}
