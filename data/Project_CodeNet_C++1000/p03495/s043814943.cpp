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
	int n,k; cin >> n >> k;
	set<int> st;
	vector<int> a(n);
	map<int, int> mp;
	priority_queue<int, vector<int>, greater<int>> q;
	rep(i, n)
	{
		cin >> a[i];
		mp[a[i]]++;
		st.insert(a[i]);
	}
	if (st.size() <= k)
	{
		cout << 0; return 0;
	}

	rep1(i, n)
	{
		if(st.count(i))
			q.push(mp[i]);
	}
	int r = st.size() - k;
	int ans = 0;
	rep(i, r)
	{
		ans += q.top();
		// cout << q.top() << endl;
		q.pop();
	}
	cout << ans << endl;
	return (0);
}
