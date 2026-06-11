#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int  main()
{
	int a,b; cin >> a >> b;

	int ans = 0;
	if (a >= b) {
		ans += a; a--;
	}
	else {
		ans += b; b--;
	}
	ans += max(a,b);
	cout << ans << endl;
	return (0);
}
