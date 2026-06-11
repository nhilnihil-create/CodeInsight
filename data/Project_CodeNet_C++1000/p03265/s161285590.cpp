#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9+1;
const int MOD = 2e9 + 9;
const ll LINF = 1e18;
using namespace std;


int main() {
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << x2 + y1 - y2 << " " << y2 + x2 - x1 << " " << x1 + y1 - y2 << " " << y1 + x2 - x1 << endl;
	return 0;
}