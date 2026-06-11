#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <utility>
using namespace std;
using ll = long long;
 
int main() {
	int h,w;
	int x,y;
	cin >> h >> w;
	cin >> x >> y;
	cout << (h-x) * (w-y) << endl;

	return 0;
}
