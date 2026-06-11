#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> P;
bool use1[101010];
bool use2[101010];

signed main()
{
	int N;
	cin >> N;
	priority_queue<P> L, L1;
	priority_queue<P, vector<P>, greater<P> > R, R1;
	for (int i = 0; i < N; i++)
	{
		int l, r;
		cin >> l >> r;
		L.push(P(l, i));
		L1.push(P(l, i));
		R.push(P(r, i));
		R1.push(P(r, i));
	}
	int now = 0;
	int ans = 0;
	int cnt = 0;
	while (1)
	{
		P p = L.top();
		L.pop();
		while (use1[p.second])
		{
			if (L.empty()) break;
			p = L.top();
			L.pop();
		}
		if (use1[p.second]) break;
		use1[p.second] = true;
		int to = p.first;
		if (to <= now) break;
		ans += to - now;
		now = to;
		cnt++;
		if (cnt == N) break;
		p = R.top();
		R.pop();
		while (use1[p.second])
		{
			if (R.empty()) break;
			p = R.top();
			R.pop();
		}
		if (use1[p.second]) break;
		use1[p.second] = true;
		to = p.first;
		if (now <= to) break;
		ans += now - to;
		now = to;
		cnt++;
		if (cnt == N) break;
	}


	ans = ans + abs(now);
	int ans1 = 0;
	cnt = 0;
	now = 0;

	while (1)
	{
		P p = R1.top();
		R1.pop();
		while (use2[p.second])
		{
			if (R1.empty()) break;
			p = R1.top();
			R1.pop();
		}
		if (use2[p.second]) break;
		use2[p.second] = true;
		int to = p.first;
		if (now <= to) break;
		ans1 += now - to;
		now = to;
		cnt++;
		if (cnt == N) break;
		p = L1.top();
		L1.pop();
		while (use2[p.second])
		{
			if (L1.empty()) break;
			p = L1.top();
			L1.pop();
		}
		if (use2[p.second]) break;
		use2[p.second] = true;
		to = p.first;
		if (to <= now) break;
		ans1 += to - now;
		now = to;
		cnt++;
		if (cnt == N) break;
	}
	cout << max (ans, ans1 + abs(now)) << endl;
}