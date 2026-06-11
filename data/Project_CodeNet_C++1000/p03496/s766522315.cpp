#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 55, M = 1010, INF = 0x3f3f3f3f;

int n;
int a[N];
vector<PII> res;

int main()
{
	cin >> n;
	
	bool flag = false;
	int maxa = -INF, mina = INF, axi, ini;
	
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		if (a[i] < mina) mina = a[i], ini = i;
		if (a[i] > maxa) maxa = a[i], axi = i;
		if (a[i] < 0) flag = true;
	}
	
	if (!flag)
	{
		for (int i = 1; i < n; i ++ ) res.push_back({i, i + 1});
	}
	else if (maxa > -mina)
	{
		for (int i = 1; i <= n; i ++ ) res.push_back({axi, i});
		for (int i = 1; i < n; i ++ ) res.push_back({i, i + 1});
	}
	else
	{
		for (int i = 1; i <= n; i ++ ) res.push_back({ini, i});
		for (int i = n; i > 1; i -- ) res.push_back({i, i - 1});
	}
	
	cout << res.size() << endl;
	for (auto u : res) cout << u.F << ' ' << u.S << endl;
	
	return 0;
}