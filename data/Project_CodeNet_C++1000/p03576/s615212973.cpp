#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 55, M = 1010;

int n, m;
PII p[N];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i ++ ) cin >> p[i].F >> p[i].S;
	
	LL res = 4e18;
	for (int a = 0; a < n; a ++ )
		for (int b = 0; b < n; b ++ )
			for (int c = 0; c < n; c ++ )
				for (int d = 0; d < n; d ++ )
					if (p[d].F > p[b].F && p[a].S > p[c].S)
					{
						int cnt = 0;
						for (int i = 0; i < n; i ++ )
							if (p[i].S <= p[a].S && p[i].S >= p[c].S)
								if (p[i].F <= p[d].F && p[i].F >= p[b].F)
									cnt ++ ;
									
						LL area = (LL)(p[d].F - p[b].F) * (p[a].S - p[c].S);
						if (cnt >= m && area <= res) res = area;
					}
	
	cout << res << endl;
	return 0;
}