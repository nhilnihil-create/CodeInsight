#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	int xx = x2 - x1, yy = y2 - y1;
	cout << x2 - yy << " " << y2 + xx << " " << x1 - yy << " " << y1 + xx << '\n';
}