#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

void b_digital_gifts(void) {
	int n;
	double total = 0;
	double btc = 380000;

	double x;
	string u;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> u;

		double x_num =x;
		
		if (u == "JPY") total += x_num;
		else            total += (x_num * btc);
	}

	cout << total << endl;
}

int main()
{
    b_digital_gifts();

    return 0;
}