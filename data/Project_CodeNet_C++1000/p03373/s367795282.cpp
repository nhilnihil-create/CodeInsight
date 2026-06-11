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


int main(){
	int a, b, c, x, y;
	
	cin >> a>>b>>c>>x>>y;

	int total = 0;
			
			if (a + b <= 2 * c) {
				total = a * x + b * y;
			}
			
			if (a+b>2*c) {
				if (x >= y) {
					if (2 * x * c<= 2 * c * y + a * (x - y)) {
						total = 2 * x * c;
					}
					else {
						total = 2 * c * y + a * (x - y);
					}
				}
				else if (x < y) {
					if (2 * c * y <= 2 * c * x + b * (y - x)) {
						total = 2 * c * y;
					}
					else {
						total = 2 * c * x + b * (y - x);
					}
				}
			}
		
			cout << total << endl;

	return 0;
}
