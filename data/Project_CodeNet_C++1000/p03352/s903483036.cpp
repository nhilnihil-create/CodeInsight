
#include <bits/stdc++.h>
using namespace std;

#define li long long int
#define rep(i, to) for (li i = 0; i < ((li)(to)); i++)
#define repp(i, start, to) for (li i = (li)(start); i < ((li)(to)); i++)

#define F first
#define S second

typedef pair<li, li> PI;

int main(void)
{
	li x;
	cin >> x;


	li res = 1;
	repp(i, 2, sqrt(x) + 1) {
		for (auto y = i * i; y <= x; y *= i) {
			res = max(res, y);
		}
	}
	cout << res << endl;

	return 0;
}