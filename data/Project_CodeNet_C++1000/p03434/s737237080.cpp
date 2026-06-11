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
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a.begin(), a.end(), greater<int>());

	int alice = 0, bob = 0, x = 0;

	for (int i = 0; i < n; i++)
	{
		if (x % 2 == 0)
		{
			alice += a[i];
			x += 1;
		}
		else if (x % 2 ==1)
		{
			bob += a[i];
			x += 1;
		}
	}

	int ans = 0;
	ans = alice - bob;
	cout << ans << endl;


}

