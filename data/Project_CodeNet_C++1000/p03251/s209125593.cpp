#include<iostream>
#include<cstdlib>
#include<utility>
#include<tuple>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
#include<queue>
#include<deque>
#include<bitset>
#include<cmath>
#include<map>
#include<iomanip>
using namespace std;
using ll = long long int;
const ll mod = 1e9 + 7;
#define rep(i, a, b) for(int i = a; i < b; i++)

int main() {
	
	int n, m, X, Y;
	cin >> n >> m >> X >> Y;

	int xmax = -100, ymin = 100;
	vector<int> x(n), y(m);
	rep(i, 0, n) {
		cin >> x[i];
		xmax = max(xmax, x[i]);
	}
	rep(i, 0, m) {
		cin >> y[i];
		ymin = min(ymin, y[i]);
	}

	if (X >= ymin || Y <= xmax || ymin <= xmax) cout << "War" << endl;
	else cout << "No War" << endl;

	return 0;
}