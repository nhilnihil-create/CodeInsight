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

struct Block
{
	int l, r, ch;
};

int n, a[N];

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie();
	//cout.tie();		

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	//~read
	scanf("%d", &n);
	forn(i, n)
		scanf("%d", &a[i]);
	//~solve
	int l = 0, r = n + 1;
	while(l < r - 1)
	{
		int ans = (l + r) >> 1;
		vector < Block > t;
		bool good = true;
		t.pb({1, a[1], 1});
		for (int i = 2; i <= n; i++)
		{
			vector < Block > v;
			if (a[i] > a[i - 1])
			{	
				v = t;
				v.pb({a[i - 1] + 1, a[i], 1});
			}
			else
			{
				for (int j = (int)t.size() - 1; j >= 0; j--)
				{
					if (t[j].ch == ans)
						continue;
					if (t[j].l > a[i])
						continue;
					for (int k = 0; k < j; k++)
						v.pb(t[k]);
					int pos = min(a[i], t[j].r);
					if (pos > t[j].l)
						v.pb({t[j].l, pos - 1, t[j].ch});
					v.pb({pos, pos, t[j].ch + 1});
					if (pos < a[i])
						v.pb({pos + 1, a[i], 1});
					break;
				}       
			}
			if (v.empty())
			{
				good = false;
				break;
			}
			t.clear();
			int ll = 1;
			for (int i = 0; i < (int)v.size(); i++)
			{
				if (i == (int)v.size() - 1 || v[i].ch != v[i + 1].ch)
				{
					t.pb({ll, v[i].r, v[i].ch});
					ll = v[i].r + 1;
				}
			}
		}
		if (good)
			r = ans;
		else	
			l = ans;
	}
	cout << r << endl;
	return 0;
}

