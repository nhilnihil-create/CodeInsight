#include <bits/stdc++.h>

#define F first
#define S second

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
	
	for (int i = 0; i < 50; i ++ )
		for (int j = 0; j < 100; j ++ )
			g[i][j] = '#';
	for (int i = 50; i < 100; i ++ )
		for (int j = 0; j < 100; j ++ )
			g[i][j] = '.';
			
	for (int i = 0; i < 50 && a; i += 2)
		for (int j = 0; j < 100 && a; j += 2)
			g[i][j] = '.', a -- ;
			
	for (int i = 51; i < 100 && b; i += 2)
		for (int j = 0; j < 100 && b; j += 2)
			g[i][j] = '#', b -- ;
	
	puts("100 100");
	for (int i = 0; i < 100; i ++ ) puts(g[i]);
	return 0;
}