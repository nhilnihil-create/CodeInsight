#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_add_and_mul(void) {
	int n, k;
	cin >> n >> k;
	int now = 1;
	int min;
	for (int i = 0; i <= n; i++) {
		now = 1;
		now = (now << (1 * i)) + k * (n-i);
		if (i == 0) min = now;
		else {
			if (now < min) min = now;
		}
	}
	cout << min << endl;
}

int main()
{
	b_add_and_mul();
    return 0;
}