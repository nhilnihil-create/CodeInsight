#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define sz 200100

int a[sz];
int h[sz];
ll tr[4 * sz];

void update(int s, int e, int i, ll val, int idx)
{
	if (s > i || e < i)
		return;
	if (s == e)
	{
		tr[idx] = val;
		return;
	}
	int m = (s + e) / 2;
	update(s, m, i, val, 2 * idx);
	update(m + 1, e, i, val, 2 * idx + 1);
	tr[idx] = max(tr[2 * idx], tr[2 * idx + 1]);
}

ll query(int s, int e, int qs, int qe, int idx)
{
	if (qs > e || qe < s)
		return 0;
	if (qs <= s && qe >= e)
		return tr[idx];
	int m = (s + e) / 2;
	ll a = query(s, m, qs, qe, 2 * idx);
	ll b = query(m + 1, e, qs, qe, 2 * idx + 1);
	return max(a, b);
}

int main()
{
	int n; ll x;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &h[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		x = query(0, n, 0, h[i] - 1, 1);
		update(0, n, h[i], x + a[i], 1);
	}

	cout << tr[1];




	return 0;
}