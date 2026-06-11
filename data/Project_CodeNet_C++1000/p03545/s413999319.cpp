#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void c_train_ticket(void) {
	string abcd;
	int a, b, c, d;
	cin >> abcd;
	a = abcd[0] - '0';
	b = abcd[1] - '0';
	c = abcd[2] - '0';
	d = abcd[3] - '0';
	char op[2] = { '+','-' };


	for (int j = 0; j < 2; j++) {
		int ab = 0;
		if (j == 0) ab = a + b;
		else        ab = a - b;
		for (int i = 0; i < 2; i++) {
			int abc = 0;
			if (i == 0) abc = ab + c;
			else        abc = ab - c;
			for (int k = 0; k < 2; k++) {
				int abcd = 0;
				if (k == 0) abcd = abc + d;
				else        abcd = abc - d;

				if (abcd == 7) {
					cout << a << op[j] << b << op[i] << c << op[k] << d << "=7" << endl;
					return;
				}
			}
		}
	}

	
}

int main()
{
    c_train_ticket();
    return 0;
}