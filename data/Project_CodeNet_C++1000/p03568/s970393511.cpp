#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
	int n;
	cin >> n;
	int all = 1, odd = 1;
	rep(i, n) {
		all *= 3;
		int a; cin >> a;
		if (a % 2 == 0) odd *= 2;
	}
	cout << all - odd << endl;
	return 0;
}