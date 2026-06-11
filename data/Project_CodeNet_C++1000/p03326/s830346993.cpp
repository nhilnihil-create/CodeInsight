#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 1010, M = 3;

int n, m;
LL w[N][M];
LL val[N];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i ++ )
		for (int j = 0; j < M; j ++ )
		 	cin >> w[i][j];
		 	
	LL res = -1e18;
	for (int i = 0; i < 1 << M; i ++ )
	{
		for (int j = 0; j < n; j ++ )
		{
			LL t = 0;
			for (int k = 0; k < M; k ++ )
				if ((i >> k) & 1) t += w[j][k];
				else t -= w[j][k];

			val[j] = t;
		}
		sort(val, val + n);
		reverse(val, val + n);
		
		LL t = 0;
		for (int i = 0; i < m; i ++ ) t += val[i];
		res = max(res, t);
	}
	
	cout << res << endl;
	
	
	return 0;
}