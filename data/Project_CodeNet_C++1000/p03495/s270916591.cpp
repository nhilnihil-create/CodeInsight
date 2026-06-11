#include <bits/stdc++.h>
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
	vector<int> a(n);
	map<int, int> mp;
	rep(i, n)
	{
		cin >> a[i];
		mp[a[i]]++;
	}
	if (mp.size() <= k)
		cout << 0 << endl;
	else
	{
		priority_queue <int, vector<int>, greater<int>> q;
		rep1(i, n)
		{
			if(mp.count(i))
				q.push(mp[i]);
		}
		int ans = 0;
		rep(i, mp.size()-k)
		{
			ans += q.top();
			q.pop();
		}
		cout << ans << endl;
	}
	return (0);
}
