#include <stdio.h>
#include <iostream>
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


//ABC123_b
int main() {
	int ans = 0;
	int ext = 0;
	rep(i, 5) {
		int a;
		cin >> a;
		ans += (a + 9) /10 * 10;
		ext = max(ext, (1000-a)%10);
	}
	ans = ans - ext;
	cout << ans << endl;
}