#include <iostream>
using namespace std;

int main()
{
	int val[9];

	for (int i = 0; i < 3; i++) {
		cin >> val[i*3] >> val[i*3+1] >> val[i*3+2];
	}

//	for (int i = 0; i < 9; i++) {
//		cout << *(val+i) << "\n";
//	}

	if (
		*(val + 1) - (*(val + 2)) == *(val + 4) - (*(val + 5)) && 
		*(val + 4) - (*(val + 5)) == *(val + 7) - (*(val + 8)) &&
		*(val) - *(val + 3) == *(val + 1) - (*(val + 4)) &&
		*(val + 1) - (*(val + 4)) == *(val + 2) - (*(val + 5)) &&
		*(val)-(*(val + 1)) == *(val + 3) - (*(val + 4)) &&
		*(val + 3) - (*(val + 4)) == *(val + 6) - (*(val + 7)) &&
		*(val + 3) - (*(val + 6)) == *(val + 4) - (*(val + 7)) &&
		*(val + 4) - (*(val + 7)) == *(val + 5) - (*(val + 8))
		) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}