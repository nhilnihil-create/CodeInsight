#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long ll;
typedef long double ld;

int  main()
{
	int n; cin >> n;
	vector <int> a(n + 1);
	vector <int> b(n + 1);
	int mini = 5001;
	int maxi = -5001;
	rep(i, n)
	{
		cin >> a[i];
		mini = min(mini, a[i]);
		maxi = max(maxi, a[i]);
	}
	int sum = 0;
	rep(i, n)
	{
		if (i == 0)
			b[i] = abs(0 - a[i]);
		else
			b[i] = abs(a[i] - a[i - 1]);
		sum += b[i];
	}

	sum += abs(0 - a[n - 1]);
	a.insert(a.begin(), 0);
	b.insert(b.begin(), 0);
	rep1(i, n)
	{
		int ans = sum - abs(a[i] - a[i-1]);
		ans -= abs(a[i] - a[i+1]);
		ans += abs(a[i+1]- a[i-1]);
		cout << ans << endl;
		// cout << a[i] << endl;
	}
	// cout << a[0] << endl;
	return 0;
}
