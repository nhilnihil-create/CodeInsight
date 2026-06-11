#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

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
	
	int mina = INF, axi, maxa = -INF, ini;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		if (a[i] < mina)
		{
			mina = a[i];
			ini = i;
		}
		if (a[i] > maxa)
		{
			maxa = a[i];
			axi = i;
		}
	}
	
	if (maxa > -mina)
	{
		for (int i = 1; i <= n; i ++ ) res.PB({axi, i});
		for (int i = 1; i < n; i ++ ) res.PB({i, i + 1});
	}
	else
	{
		for (int i = 1; i <= n; i ++ ) res.PB({ini, i});
		for (int i = n; i > 1; i -- ) res.PB({i, i - 1});
	}
	
	cout << res.size() << endl;
	for (auto u : res) cout << u.F << ' ' << u.S << endl;
    return 0;
}