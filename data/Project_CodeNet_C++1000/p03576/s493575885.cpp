#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 55, M = 110;

int n, m;
int x[N], y[N];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i ++ ) cin >> x[i] >> y[i];
	
	LL res = 1LL << 62;
	for (int i = 0; i < n; i ++ )
		for (int j = 0; j < n; j ++ )
			for (int k = 0; k < n; k ++ )
				for (int l = 0; l < n; l ++ )
					if (x[i] <= x[j] && y[k] <= y[l])
					{
						int cnt = 0;
						for (int u = 0; u < n; u ++ )
							if (x[u] <= x[j] && x[u] >= x[i] && y[u] <= y[l] && y[u] >= y[k])
								cnt ++ ;
						if (cnt >= m) res = min(res, (LL)(x[j] - x[i]) * (y[l] - y[k]));
					}
	
	cout << res << endl;
	return 0;
}