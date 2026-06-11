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
int x[N], y[N];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i ++ ) cin >> x[i] >> y[i];
	
	LL res = 4e18;
	for (int a = 0; a < n; a ++ )
		for (int b = 0; b < n; b ++ )
			for (int c = 0; c < n; c ++ )
				for (int d = 0; d < n; d ++ )
					if (x[a] > x[b] && y[c] > y[d])
					{
						int cnt = 0;
						for (int i = 0; i < n; i ++ )
							if (x[i] <= x[a] && x[i] >= x[b])
								if (y[i] <= y[c] && y[i] >= y[d])
									cnt ++ ;
						
						if (cnt >= m)
						{
							LL area = (LL)(x[a] - x[b]) * (LL)(y[c] - y[d]);
							res = min(res, area);
						}
					}
	
	cout << res << endl;
    return 0;
}