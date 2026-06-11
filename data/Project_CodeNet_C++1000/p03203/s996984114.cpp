//By Don4ick 
//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;

#define forn(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define y1 qewr1234

const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};

const int N = (int)2e5 + 228;

using namespace std;

bitset < N > b;
vector < int > g[N];
int n, w, h;

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie();
	//cout.tie();		

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	b[1] = 1;
	scanf("%d%d%d", &h, &w, &n);
	forn(i, n)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].pb(y);
	}
	for (int i = 2; i <= h; i++)
	{	
		for (auto it : g[i])
		{	
			if (b[it])
			{
				cout << i - 1 << endl;
				return 0;
			}
		}
		b |= b << 1;
		for (auto it : g[i])	
			b[it] = false;	
	}
	cout << h << endl;
	
	return 0;
}

