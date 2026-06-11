#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 510, M = 1010;

int n, m, k;
int f[N][N];
int L[N][N], R[N][N];

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	while (m -- )
	{
		int l, r;
		scanf("%d%d", &l, &r);
		L[l][r] ++ , R[r][l] ++ ;
	}
	
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= n; j ++ )
		{
			L[i][j] += L[i][j - 1];
			R[i][j] += R[i][j - 1];
		}
	
	for (int len = 1; len <= n; len ++ )
		for (int l = 1; l + len - 1 <= n; l ++ )
		{
			int r = l + len - 1;
			if (r > l + 1) f[l][r] += f[l + 1][r - 1];
			f[l][r] += L[l][r] - L[l][l - 1];
			f[l][r] += R[r][r] - R[r][l - 1];
			f[l][r] -= L[l][r] - L[l][r - 1];
		}
	
	while (k -- )
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", f[l][r]);
	}
    return 0;
}