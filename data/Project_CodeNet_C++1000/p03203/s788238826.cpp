#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 200100;
map<int, bool> mark[maxn];
int h, w, n;
int x[maxn], y[maxn];
int mx[maxn] = {0};
int ans;
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> h >> w >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> x[i] >> y[i];
		mark[x[i]][y[i]] = 1;
	}
	ans = h + 1;
	int nowx = 1, nowy = 1;
	mx[2] = 1;
	for(int i = 2; i <= h; i ++)
	{
		nowx ++;
		if(mark[nowx][nowy])
		{
			ans = i;
			break;
		}
		if(!mark[nowx][nowy + 1])
			nowy ++;
		mx[i + 1] = nowy;
	}
	for(int i = 1; i <= n; i ++)
		if(x[i] < ans && mx[x[i]] >= y[i])
			ans = x[i];
	cout << ans - 1 << endl;
	return 0;
}