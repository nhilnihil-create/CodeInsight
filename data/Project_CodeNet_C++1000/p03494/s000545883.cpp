#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_shift_only(void) {
	int n;
	int* a;
	cin >> n;
	a = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	bool det_odd = false;
	while (true) {
		for (int i = 0; i < n; i++) {
			if ((a[i] & 0x1) == 0x1) {
				det_odd = true;
			}
			else {
				a[i] = a[i] >> 1;
			}
			if (det_odd)break;
		}
		if (det_odd)break;
		cnt++;
	}
	cout << cnt << endl;
}

int main()
{
	b_shift_only();
    return 0;
}