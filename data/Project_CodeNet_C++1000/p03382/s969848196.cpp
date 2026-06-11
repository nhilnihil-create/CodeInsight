#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
using namespace std;

typedef long long ll;



int main() {
	int n; cin >> n;
	vector<int> a(n);
	int ma = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ma = max(ma, a[i]);
	}
	int r = 0;
	for (int i = 0; i < n; i++) {
		if (abs(a[i] - ma / 2) < abs(r - ma / 2)) r = a[i];
	}
	cout << ma << " " << r << endl;
	return 0;
}