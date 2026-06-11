#include <bits/stdc++.h>
using namespace std;
long long mypow(long long x, long long y)
{
	long long result = 1;
	while (y != 0) {
		if (y%2 != 0) {
			result *= x;
			y -= 1;
		}	
		x *= x;
		y /= 2;
	}
	return result;
}
int main(void)
{
	long long a, b;
	cin >> a >> b;
	uint64_t ans = 0;
	for (long long i = 0; i <= 40; i++) {
		long long acount, bcount;
		{
		long long n = (a)/mypow(2, i+1);
		long long m = (a)%mypow(2, i+1);
		acount = n*mypow(2, i) + max(0LL, m-mypow(2LL, (long long)i));
		}
		{
		long long n = (b+1)/mypow(2, i+1);
		long long m = (b+1)%mypow(2, i+1);
		bcount = n*mypow(2, i) + max(0LL, m-mypow(2LL, (long long)i));
		}
		ans += (bcount - acount)%2 * mypow(2, i);
	}
	cout << ans << endl;
	return 0;
}