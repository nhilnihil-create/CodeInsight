#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 55, M = 8010, INF = 0x3f3f3f3f;

int n;
int a[N];
vector<PII> res;

void add(int x, int u)
{
	for (int i = 1; i <= n; i ++ )
	{
		a[i] += x;
		res.push_back({u, i});
	}
}

int main()
{
	cin >> n;
	int maxa = -INF, axi, mina = INF, ini;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		if (a[i] > maxa) maxa = a[i], axi = i;
		if (a[i] < mina) mina = a[i], ini = i;
	}
	
	if (abs(maxa) > abs(mina)) add(maxa, axi);
	else add(mina, ini);
	
	if (a[1] > 0)
	{
		for (int i = 1; i < n; i ++ ) res.push_back({i, i + 1});
	}
	else
	{
		for (int i = n; i > 1; i -- ) res.push_back({i, i - 1});
	}
	
	cout << res.size() << endl;
	for (auto u : res) cout << u.F << ' ' << u.S << endl;
	
	return 0;
}