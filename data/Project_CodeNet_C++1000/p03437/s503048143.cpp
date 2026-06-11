#include <bits/stdc++.h>
using namespace std;

#define li long long int
#define rep(i, to) for (li i = 0; i < ((li)(to)); i++)
#define repp(i, start, to) for (li i = (li)(start); i < ((li)(to)); i++)



int main() {
	li x, y;
	cin >> x >> y;
	if (x % y == 0) {
		puts("-1");
		return 0;
	}
	cout << x*(y - 1) << endl;

	return 0;
}
