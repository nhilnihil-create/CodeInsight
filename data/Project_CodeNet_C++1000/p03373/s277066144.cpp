#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <climits>

using namespace std;

int main() {
	int a, b, c, x, y;

	cin >> a >> b >> c >> x >> y;

	int total = a*x+b*y;


			for (int k = 0 ;k<=2*max(x,y);k++) {
					
				int d = 0;
				if (x-k/2>0) {
					d = x - k / 2;
				}

				int e = 0;
				if (y - k / 2 > 0) {
					e = y - k / 2;
				}

					int total1 = a * d + b * e + c * k;

					if (total1<total) total = total1;

			}


	cout << total << endl;

	return 0;
}