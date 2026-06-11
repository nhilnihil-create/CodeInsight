#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

void b_resale(void) {
	int n;
	int* v;
	int* c;
	cin >> n;
	v = (int*)calloc(n, sizeof(int));
	c = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)cin >> v[i];
	for (int i = 0; i < n; i++)cin >> c[i];
	int* d;
	d = (int*)calloc(n, sizeof(int));
	int max = 0;
	bool all_minus = true;
	for (int i = 0; i < n; i++) {
		d[i] = v[i] - c[i];
		if (d[i] > 0) all_minus = false;
	}
	sort(d, d + n);
	if (all_minus)max = 0;
	else {
		for (int i = 0; i < n; i++) {
			if (d[i] >= 0)max += d[i];
		}
	}

	cout << max << endl;
}

int main()
{
    b_resale();

    return 0;
}