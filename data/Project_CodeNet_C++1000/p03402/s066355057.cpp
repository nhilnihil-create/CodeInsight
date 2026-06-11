#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 110, M = 110;

int n, m;
char g[N][N];

int main()
{	
	cin >> n >> m;
	for (int i = 0; i < 50; i ++ )
		for (int j = 0; j < 100; j ++ )
			g[i][j] = '#';
	for (int i = 50; i < 100; i ++ )
		for (int j = 0; j < 100; j ++ )
			g[i][j] = '.';
			
	n -- , m -- ;
	for (int i = 0; i < 49 && n; i += 2)
		for (int j = 0; j < 100 && n; j += 2)
			g[i][j] = '.', n -- ;
			
	for (int i = 51; i < 100 && m; i += 2)
		for (int j = 0; j < 100 && m; j += 2)
			g[i][j] = '#', m -- ;
			
	puts("100 100");
	for (int i = 0; i < 100; i ++ ) puts(g[i]);
	return 0;
}