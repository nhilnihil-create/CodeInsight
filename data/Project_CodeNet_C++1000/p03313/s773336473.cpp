#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<double> point;
#define F first
#define S second

struct two
{
	int a, b;
	two() : a(0), b(0) {}
	void update(int x)
	{
		if (x > a) swap(x, a);
		if (x > b) swap(x, b);
	}
	void merge(two t)
	{
		update(t.a);
		update(t.b);
	}
};

int main()
{
	#ifdef DGC
		freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(1<<n);
	vector<two> dp(1<<n);
	for (auto &i : a)
	{
		cin >> i;
		dp[&i-&a[0]].update(i);
	}
	
	for (int j = 0; j < n; ++j)
		for (int i = 0; i < 1<<n; ++i)
			if (~i>>j&1)
				dp[i|1<<j].merge(dp[i]);

	dp.emplace_back();
	for (int i = 1; i < 1<<n; ++i)
	{
		cout << dp[i].a+dp[i].b << "\n";
		if (dp[i].a+dp[i].b > dp[i+1].a+dp[i+1].b)
			dp[i+1] = dp[i];
	}

	return 0;
}
