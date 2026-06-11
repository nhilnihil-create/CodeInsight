#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long ll;
typedef long double ld;

int  main()
{
	long n,x; cin >> n >> x;
	vector <long> a(n+1);
	rep(i, n)
		cin >> a[i];
	a[n] = x;
	sort(a.begin(), a.end());
	long ans = LONG_MAX;
	vector <long> b;
	for(long i = 0; i < n; i++)
	{
		ans = min(abs(a[i] - a[i+1]), ans);
		b.push_back(abs(a[i] - a[i+1]));
		// cout << abs(a[i] - a[i+1]) << endl;
	}
	long cnt = 0;
	while (ans > 0)
	{
		cnt = 0;
		rep(i, b.size())
		{
			if (b[i] % ans == 0)
				cnt++;
		}
		if (cnt == b.size())
		{
			break;
		}
		ans--;
	}
	cout << ans << endl;
	return 0;
}