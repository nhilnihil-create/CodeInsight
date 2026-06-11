#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int n, k; cin >> n >> k;

	int ans = 1;
	rep(i, n)
	{
		if (ans * 2 - ans <= k)
			ans *= 2;
		else
			ans += k;
	}
	cout << ans << endl;
	return (0);
}
