#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<stdio.h>
#include<queue>
#include<map>
#include<stack>
using namespace std;
int dx[] = { -1,0,0,1,-1,-1,1,1,0 };
int dy[] = { 0,1,-1,0,1,-1,1,-1,0 };
/*
int main()
{
int r, c;
cin >> r >> c;
int sy, sx, gy, gx;
vector<vector<char>>field(r,vector<char>(c));
sy--, sx--, gy--, gx--;
for (int i = 0; i < r; i++)
{
for (int j = 0; j < c; j++)
{
cin >> field[i][j];
}
}
queue<pair<int,int>>q;
q.push({ sx,sy });
vector<vector<int>>d(c, vector<int> (r, -1));
d[sx][sy] = 0;

while (!q.empty())
{
pair<int, int>p = q.front;
q.pop();
for (int i = 0; i < 4; i++)
{
int nx = p.first + dx[i], ny = p.second + dy[i];
if (nx < 0 || ny < 0 || nx >= c || ny >= r || d[nx][ny] != -1 || field[nx][ny] == '#')continue;
q.push({ nx,ny });
d[nx][ny] = d[p.first][p.second] + 1;
}
}

cout << d[gx][gy] << endl;
}*/


int main()
{
	int  n, m, x;
	cin >> n >> m >> x;
	vector<int>a(m);
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}

	int ans1 = 0, ans2 = 0;

	for (int i = 0; i < m; i++)
	{
		if (a[i] < x)
		{
			ans1 += 1;
		}
		else
		{
			ans2 += 1;
		}
	}

	cout << min(ans1, ans2) << endl;
	


}

