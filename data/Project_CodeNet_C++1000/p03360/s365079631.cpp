#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef struct _data {
	int x;
	int y;
} data;

int  main()
{
	long n[3];
	int k;
	cin >> n[0] >> n[1] >> n[2] >> k;
	int max  =0;
	int idx = 0;
	int ans = 0;
	rep(i, 3)
	{
		if (max <= n[i])
		{
			max = n[i];
			idx = i;
		}
	}
	rep (i, k)
		max *= 2;
	rep(i, 3)
	{
		if (i != idx)
			ans += n[i];
		if (i == idx)
			ans += max;
	}
	cout << ans << endl;
	return (0);
}
