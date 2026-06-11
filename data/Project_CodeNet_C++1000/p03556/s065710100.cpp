#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_around_square(void) {
	int n;
	cin >> n;

	int sqr_int;
	double sqr_duble;
	int max_sqr;
	for (int i = n; i >= 0; i--) {
		sqr_duble = sqrt(i);
		if (sqr_duble - int(sqr_duble) == 0) {
			max_sqr = i;
			break;
		}
	}
	cout << max_sqr << endl;
}

int main()
{
	b_around_square();
    return 0;
}