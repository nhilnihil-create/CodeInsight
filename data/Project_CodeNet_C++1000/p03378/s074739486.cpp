#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
	int n, m , x;
	cin >> n >> m >> x;
	int cntL = 0, cntR = 0;
	rep(i, m) {
		int a; cin >> a;
		if (a < x) cntL++;
		else if (a > x) cntR++;
	}
	cout << min(cntL, cntR) << endl;
	return 0;
}