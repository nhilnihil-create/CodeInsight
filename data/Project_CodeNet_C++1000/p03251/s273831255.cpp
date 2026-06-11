#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;


int main(){
	int n, m, xx, yy, maxx = -MOD, miny = MOD;
	cin >> n >> m >> xx >> yy;
	vector<int> x(n), y(m);
	for (int i = 0; i < n; i++){
		cin >> x[i];
		maxx = max(maxx, x[i]);
	}
	for (int i = 0; i < m; i++){
		cin >> y[i];
		miny = min(miny, y[i]);
	}

	if (max(xx, maxx) < min(yy, miny)) cout << "No War" << endl;
	else cout << "War" << endl;
	return 0;
}