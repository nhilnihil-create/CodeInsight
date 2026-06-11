#include <bits/stdc++.h>

#define F first 
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 200010, M = 110;

int n;
int cnt[M];
int f[M][M];

int main()
{
	cin >> n;
	for (int i = 2; i <= n; i ++ )
	{
		int t = i;
		for (int j = 2; j <= t / j; j ++ )
			while (t % j == 0)
			{
				cnt[j] ++ ;
				t /= j;
			}
		if (t > 1) cnt[t] ++ ;
	}
	
	f[0][1] = 1;
	for (int i = 0; i < M; i ++ )
		for (int j = 1; j <= 75; j ++ )
			for (int k = 0; k <= cnt[i]; k ++ )
				if ((k + 1) * j > 75) break;
				else f[i + 1][j * (k + 1)] += f[i][j];
	
	cout << f[n][75] << endl;
    return 0;
}
