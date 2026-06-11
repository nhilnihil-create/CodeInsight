#include "bits/stdc++.h"

using namespace std;

inline long digit_sum(long x)
{
	long res = 0;
	while(x)
	{
		res += x % 10;
		x /= 10;
	}
	return res;
}

inline bool check(long x, long y)
{
	return (x * (digit_sum(y)) <= y * digit_sum(x));
}

long best = 1e15;

void solve(void)
{
	vector<long> ans;
	for (long k = 1e11; k > 0; k /= 10)
	{
		for (long i = 10000; i >= 1001; i--)
		{
			long n = k * i - 1;
			if (check(n, best))
			{
				ans.push_back(n);
				best = n;
			}
		}
	}
	for (long n = 999; n >= 1; n--)
	{
		if (check(n, best))
		{
			ans.push_back(n);
			best = n;
		}
	}
	reverse(ans.begin(), ans.end());
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cout << ans[i] << '\n';
	}
}

int main()
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
