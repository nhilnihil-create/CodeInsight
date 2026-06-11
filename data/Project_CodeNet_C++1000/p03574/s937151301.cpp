#include <bits/stdc++.h>

#define SIS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define lowbit(x) (x & -x)
#define PI 3.14159265358979323846264338327950L
typedef long long ll;
using namespace std;
const int MAX = 0x7ffffff;
const int N = 55;
int t;
char a[N][N];
int b[N][N];
int ne[8][2] = {{1,0},{-1,0},{0,1},{0,-1},
{1,1},{1,-1},{-1,1},{-1,-1}};
int check(int x,int y)
{
	int ans = 0;
	for(int i = 0;i < 8;i ++)
	{
		int nx = x + ne[i][0];
		int ny = y + ne[i][1];
		if(a[nx][ny] == '#')ans++;
	}
	return ans;
}
void slove()
{
	int h , w;
	cin >> h >> w;
	for(int i = 1;i <= h ;i ++)
	{
		for(int j = 1;j <= w;j ++)
			cin >> a[i][j];
	}
	for(int i = 1;i <= h;i ++)
	{
		for(int j = 1;j <= w;j ++)
		{
			if(a[i][j] != '#')
				cout << check(i,j);
			else cout << '#';
		}
		cout << endl;
	}
}
int main()
{
	SIS;
	slove();
}