
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_maximum_sum(void) {
	int a[3];
	int k;
	int max = 0;
	int sum = 0;
	cin >> a[0] >> a[1] >> a[2] >> k;

	sort(a, a + 3, greater<int>());

	for (int i = 1; i <= k; i++) {
		a[0] = a[0] << 1;
	}

	cout << a[0] + a[1] + a[2] << endl;
}

int main()
{
	b_maximum_sum();
    return 0;
}