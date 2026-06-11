#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)


int main() {
	int X;
	cin >> X;

	int ans = 1;
	for (int i=2; i<=X; i++) {
		int res = i;
		while (res<=X) {
			res*=i;
			if (res<=X) {
				ans = max(ans, res);
			}
		}
	}
	cout << ans << endl;
}