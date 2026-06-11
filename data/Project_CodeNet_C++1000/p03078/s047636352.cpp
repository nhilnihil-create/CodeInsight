#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#define rep(i, n) for(i = 0; i < n; i++)
#define int long long
using namespace std;

int x, y, z, k;
int a[1000];
int b[1000];
int c[1000];
int bc[1000000];

signed main() {
	int i, j;
	
	cin >> x >> y >> z >> k;
	rep(i, x) cin >> a[i];
	rep(i, y) cin >> b[i];
	rep(i, z) cin >> c[i];
	rep(i, y) rep(j, z) bc[i * z + j] = b[i] + c[j];
	sort(bc, bc + y * z, greater<int>());
	
	vector<int> vec;
	rep(i, x) {
		rep(j, min(y * z, k)) {
			vec.push_back(a[i] + bc[j]);
		}
	}
	sort(vec.begin(), vec.end(), greater<int>());
	
	rep(i, k) cout << vec[i] << endl;
	return 0;
}