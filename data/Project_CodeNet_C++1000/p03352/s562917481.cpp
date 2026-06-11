
#include <bits/stdc++.h>
using namespace std;

#define li long long int
#define rep(i, to) for (li i = 0; i < ((li)(to)); i++)
#define repp(i, start, to) for (li i = (li)(start); i < ((li)(to)); i++)

int main(void)
{
	li x;
	cin >> x;

	li res = 1;
	for (li b = 2; b <= sqrt(x); b++) {
		for (li bp = b * b; bp <= x; bp *= b) {
			res = max(res, bp);
		}
	}
	cout << res << endl;

	return 0;
}