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
	int a, b, k;
	
	cin >> a >> b >> k;

	int count=0;
	int ans = 0;

	for (int i = 100; i > 0; i--) {
		if (a % i == 0 && b % i == 0)count++;

		if (count == k) {
			ans = i;
			break;
		}
	}

	cout << ans << endl;

	return 0;
}