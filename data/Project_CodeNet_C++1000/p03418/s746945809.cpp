#include <bits/stdc++.h>
#define FOR(i, a, b) for(long long i = (a); i <=(b); i++)
using namespace std;

signed main(void)
{
	long long n, k, cnt;
	cin >> n >> k;
	
	cnt = 0;
	FOR(b, 1, n)
	{
		long long p = n / b;
		long long r = n % b;
		cnt += p * max(b - k, (long long)0);
		if (k == 0)
			cnt--;
		cnt += max(r - k + 1, (long long)0);
	}
	cout << cnt << endl;
	return 0;
}
