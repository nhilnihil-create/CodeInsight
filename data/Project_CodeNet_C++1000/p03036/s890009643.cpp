#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;


void b_algae(void) {
	int r, d, x;
	cin >> r >> d >> x;
	int now = x;

	for (int i = 0; i < 10; i++) {
		int before = now;
		now = r * before - d;
		cout << now << endl;
	}
}

int main()
{
    b_algae();

    return 0;
}