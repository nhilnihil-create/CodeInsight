#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 100005;
int par[MAX_N],size[MAX_N],p[MAX_N];

void init()
{
	rep(i,MAX_N)
	{
		par[i] = i;
		size[i] = 1;
	}
	return;
}

int find(int x)
{
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}

void unite(int x, int y)
{
	if (par[x] == par[y]) return;
	x = find(x);
	y = find(y);
	if (size[x] > size[y]) swap(x,y);
	par[x] = y;
	if (size[x] == size[y]) size[y]++;
	return;
}

bool same(int x, int y)
{
	return find(x) == find(y);
}

int main()
{
	init();
	int N,M;
	cin >> N >> M;
	rep(i,N)
	{
		cin >> p[i+1];
	}
	rep(i,M)
	{
		int x,y;
		cin >> x >> y;
		unite(x,y);
	}
	int ans = 0;
	rep(i,N)
	{
		if (same(p[i+1],i+1)) ans++;
	}
	cout << ans << endl;
	return 0;
}