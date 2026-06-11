#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_small_and_large_integers(void) {
	int a, b, k;
	cin >> a >> b >> k;
	int a_start = a;
	int a_end = a + k - 1;

	int b_start = b - k + 1;
	int b_end = b;

	if (a_end < b_start) {
		for (int i = a; i < a + k; i++) cout << i << endl;
		for (int i = b - k + 1; i <= b; i++) cout << i << endl;
	}
	else {
		for (int i = a; i <= b; i++) {
			cout << i << endl;
		}
	}
}

int main()
{
	b_small_and_large_integers();
    return 0;
}