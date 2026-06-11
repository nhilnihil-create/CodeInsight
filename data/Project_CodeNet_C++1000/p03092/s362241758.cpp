#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

typedef long long ll;

const int MAXN = 5005;
const ll INF = 1e18;

int n,A,B;
int p[MAXN];

ll ans;
ll f[MAXN][MAXN];
ll MIN[MAXN][MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> A >> B;
	for (int v,i = 1;i <= n;i++)
	{
		cin >> v;
		p[v] = i;
	}
	ans = INF;
	for (int i = 0;i <= n;i++)
		for (int j = 0;j <= n;j++)
			f[i][j] = MIN[i][j] = INF;
	f[0][0] = 0;
	for (int i = 0;i <= n;i++)
		MIN[0][i] = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= n;j++)
		{
			if (j == p[i])
				f[i][j] = MIN[i - 1][j - 1];
			else if (j < p[i])
				f[i][j] = MIN[i - 1][j] + B;
			else
				f[i][j] = MIN[i - 1][j] + A;
			if (!j)
				MIN[i][j] = f[i][j];
			else
				MIN[i][j] = min(MIN[i][j - 1],f[i][j]);
			if (i == n)
				ans = min(ans,f[i][j]);
		}
	cout << ans << endl;
	return 0;
}
