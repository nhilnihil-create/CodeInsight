#include <iostream>
using namespace std;
using i64 = int64_t;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n; cin >> n;
	i64* a = new i64[n];
	i64* b = new i64[n];
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> b[i];
	
	i64 ac = 0;
	i64 bc = 0;
	rep(i, 0, n) {
		if (a[i] > b[i]) bc += a[i] - b[i];
		else ac += (b[i] - a[i]) / 2;
	}
	if (ac >= bc) cout << "Yes";
	else cout << "No";
  	delete[] a;
	delete[] b;
	return 0;
}
