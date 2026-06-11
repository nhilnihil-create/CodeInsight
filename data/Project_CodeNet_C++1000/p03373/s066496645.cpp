#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <stack>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)

using namespace std;


int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int sum = 0;
	if (2*c < a + b) {
		int  z = min(x, y);
		sum += z * c * 2;
		if (x - z != 0)sum += (x - z) * a;
		else sum += (y - z) * b;
		if (sum > 2 * c*max(x,y))sum = 2 * c*max(x, y);
	}
	else sum = (x*a) + (y*b);
	cout << sum;
}