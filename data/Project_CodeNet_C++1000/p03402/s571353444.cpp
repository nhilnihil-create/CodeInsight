#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 110, M = 1010;

int a, b;
char g[N][N];

int main()
{
	cin >> a >> b;
	a -- , b -- ;
	
	for (int i = 1; i <= 100; i ++ )
		for (int j = 1; j <= 100; j ++ )
			g[i][j] = i <= 50 ? '#' : '.';
			
	for (int i = 1; a && i <= 49; i += 2)
		for (int j = 1; a && j <= 100; j += 2)
			g[i][j] = '.', a -- ;
			
	for (int i = 52; b && i <= 100; i += 2)
		for (int j = 1; b && j <= 100; j += 2)
			g[i][j] = '#', b -- ;
	
	puts("100 100");
	for (int i = 1; i <= 100; i ++ ) puts(g[i] + 1);
	return 0;
}