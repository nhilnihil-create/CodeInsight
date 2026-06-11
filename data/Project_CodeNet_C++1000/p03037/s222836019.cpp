#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000

int main() {
	int n, m;
	cin >> n >> m;

	int l, r ;
	int tempL=0, tempR=MAX;
	for (int i = 0; i < m; i++) {
		cin >> l >> r;
		tempL = max(l, tempL);
		tempR = min(r, tempR);
	}

	int ans = tempR - tempL + 1;
	if (ans < 0) { ans = 0; }
	cout << ans << endl;
}
