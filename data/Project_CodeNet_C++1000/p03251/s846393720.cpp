#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	vector<int> vx(n, 0), vy(m, 0);
	for (int i = 0; i < n; i++) {
		cin >> vx[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> vy[i];
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	x = max(x, vx.back());
	y = min(y, vy[0]);
	if (x < y)
		cout << "No War" << endl;
	else
		cout << "War" << endl;
}
