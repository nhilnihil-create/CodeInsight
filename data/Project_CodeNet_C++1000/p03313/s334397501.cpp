#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long 
using namespace std;

const int maxn = (1 << 18) + 100;
ll a[maxn];

struct node
{
	int pos1; int pos2;
};
node p[maxn];

void update(int x, node& p)
{
	if (x == p.pos1 || x == p.pos2) return;
	if (a[x] >= a[p.pos1]) { p.pos2 = p.pos1; p.pos1 = x; }
	else if (a[x] >= a[p.pos2]) { p.pos2 = x; }
}

int main()
{
	memset(a, 0, sizeof(a));
	int n; cin >> n;
	int N; N = (1 << n);
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		p[i].pos1 = i; p[i].pos2 = N;
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i >> j & 1) == 0) continue;
			int k = (1 << j);
			update(p[(i^k)].pos1, p[i]);
			update(p[(i^k)].pos2, p[i]);
		}
	}

	ll ans = 0;
	for (int i = 1; i < N; i++)
	{
		ans = max(ans, a[p[i].pos1] + a[p[i].pos2]);
		cout << ans << endl;
	}
	return 0;
}