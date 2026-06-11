#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long ll;
typedef long double ld;

int gcd(int a, int b)
{
	if (a % b == 0)
		return b;
	else
		return (gcd(b, a % b));
}

int  main()
{
	long n,x; cin >> n >> x;
	vector <long> a(n+1);
	rep(i, n)
		cin >> a[i];
	a[n] = x;
	sort(a.begin(), a.end());
	long ans = abs(a[1] - a[0]);

	for(long i = 0; i < n; i++)
	{
		ans = gcd(ans, abs(a[i] - a[i+1]));
	}
	cout << ans << endl;
	return 0;
}