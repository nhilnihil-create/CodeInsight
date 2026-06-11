#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e13;

int main()
{
	ll N, K;
	cin >> N >> K;
	vector<vector<ll>> s(N);
	for (int i = 0; i < N; i++)
	{
		ll t, d;
		cin >> t >> d;
		t--;
		s[t].push_back(d);
	}

	for (auto &v : s)
	{
		sort(v.begin(), v.end(), greater<ll>());
		if (v.empty())
			v.push_back(-INF);
	}

	sort(s.begin(), s.end(), [](vector<ll> a, vector<ll> b) { return a[0] > b[0]; });

	// まずK種類選ぶ
	ll cur = 0;
	priority_queue<ll> pq;

	for (int i = 0; i < K; i++)
	{
		cur += s[i][0];
		for (int j = 1; j < s[i].size(); j++)
			pq.push(s[i][j]);
	}
	for (int i = K; i < N; i++)
		for (int j = 0; j < s[i].size(); j++)
			pq.push(s[i][j]);

	ll ans = cur + K * K;
	for (ll x = K - 1; x >= 1; x--)
	{
		ll v = s[x][0];
		ll w = pq.top();
		if (v < w)
		{
			pq.pop();
			cur += w;
			pq.push(v);
			cur -= v;
			ans = max(ans, cur + x * x);
		}
		else
		{
			break;
		}
	}
	cout << ans << endl;
}
