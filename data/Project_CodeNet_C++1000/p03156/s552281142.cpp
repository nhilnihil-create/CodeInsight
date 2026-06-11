#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, a, b;
	int A, B, C, ans;

	cin >> n >> a >> b;
	A = B = C = 0;
	rep(i, n)
	{
		int x;
		cin >> x;
		if (x <= a)
			A++;
		else if (x <= b)
			B++;
		else
			C++;
	}
	ans = min(A, min(B, C));
	cout << ans << endl;
	return 0;
}
