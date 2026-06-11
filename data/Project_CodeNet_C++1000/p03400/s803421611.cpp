#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_chocolate(void) {
	int n, d, x;
	int* a;
	cin >> n >> d >> x;
	a = (int*)calloc(n, sizeof(int));
	if (a == NULL) {
		return;
	}

	for (int i = 0; i < n; i++) cin >> a[i];

	int sum = 0;
	for (int i = 0; i < n; i++) {
		int day = 0;
		int ofs = 0;
		while (true) {
			day = (ofs)*a[i] + 1;
			if (day > d)break;
			sum++;
			ofs++;
		}
	}

	cout << sum + x << endl;
}

int main()
{
	b_chocolate();
    return 0;
}