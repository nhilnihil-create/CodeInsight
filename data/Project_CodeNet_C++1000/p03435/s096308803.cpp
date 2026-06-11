#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void c_takahashis_information(void) {
	int c[3][3];
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			cin >> c[j][i];
		}
	}
	int a[3], b[3];
	for (int i = 0; i <= 100; i++) {
		a[0] = i;
		b[0] = c[0][0] - a[0];
		b[1] = c[0][1] - a[0];
		b[2] = c[0][2] - a[0];

		//a1
		int a1_1 = c[1][0] - b[0];
		int a1_2 = c[1][1] - b[1];
		int a1_3 = c[1][2] - b[2];
		if ((a1_1 != a1_2) || (a1_2 != a1_3) || (a1_3 != a1_1)) continue;
		//a2
		int a2_1 = c[2][0] - b[0];
		int a2_2 = c[2][1] - b[1];
		int a2_3 = c[2][2] - b[2];
		if ((a2_1 != a2_2) || (a2_2 != a2_3) || (a2_3 != a2_1)) continue;

		cout << "Yes" << endl;
		return;
	}
	cout << "No" << endl;
}

int main()
{
    c_takahashis_information();
    return 0;
}
