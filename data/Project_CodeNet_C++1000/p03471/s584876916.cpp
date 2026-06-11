#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void c_otoshidama(void) {
	int n, y;
	cin >> n >> y;
	int total = 0;

	for (int k = 0; k <= n; k++) {
		for (int j = 0; j <= n - k; j++) {
			int i = n - k - j;
			total = 10000 * k + 5000 * j + 1000 * i;
			if (total == y) {
				cout << k << " " << j << " " << i << endl;
				return;
			}
		}
	}
	cout << "-1 -1 -1" << endl;
}

int main()
{
    c_otoshidama();
    return 0;
}