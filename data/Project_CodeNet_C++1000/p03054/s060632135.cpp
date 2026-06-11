#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 200100;
int n, m, stx, sty, len;
string s, t;
char d[4] = {'L', 'R', 'U', 'D'};
int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
bool in(int x, int y)
{
	return x > 0 && x <= n && y > 0 && y <= m;
}
bool can(int x)
{
	int nowx = stx, nowy = sty;
	for(int i = 0; i < len; i ++)
	{
		if(s[i] == d[x])
		{
			nowx += dir[x][0];
			nowy += dir[x][1];
			if(!in(nowx, nowy))
				return 1;
		}
		if(t[i] == d[x ^ 1] && in(nowx + dir[x ^ 1][0], nowy + dir[x ^ 1][1]))
		{
			nowx += dir[x ^ 1][0];
			nowy += dir[x ^ 1][1];
		}
	}
	return 0;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m >> len >> stx >> sty;
	cin >> s >> t;
	for(int i = 0; i < 4; i ++)
		if(can(i))
		{
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
	return 0;
}