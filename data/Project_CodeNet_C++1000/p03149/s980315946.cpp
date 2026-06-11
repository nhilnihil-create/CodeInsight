#include <iostream>

using namespace std;

int main()
{
	int N[4];
	cin >> N[0] >> N[1] >> N[2] >> N[3];

	bool flat_N[4];
	flat_N[0] = false;//1
	flat_N[1] = false;//9
	flat_N[2] = false;//7
	flat_N[3] = false;//4

	for (int i = 0; i < 4; i++) {
		if (N[i] == 1) {
			flat_N[0] = true;
		}
		else if (N[i] == 9) {
			flat_N[1] = true;
		}
		else if (N[i] == 7) {
			flat_N[2] = true;
		}
		else if (N[i] == 4) {
			flat_N[3] = true;
		}
	}

	int count = 0;
	for (int i = 0; i < 4; i++) {
		if (flat_N[i]) {
			count++;
		}
	}

	if (count == 4) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

}