#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, k, aa, bb, i;
	cin >> a >> b >> k;
	for (i = 0; i < k; i++) {
		if (i % 2 == 0) {
			b += a / 2;
			a /= 2;
		}
		else {
			a += b / 2;
			b /= 2;
		}
		//cout << a << " " << b << "\n";
	}
	cout << a << " " << b << "\n";
		
	return 0;
}
