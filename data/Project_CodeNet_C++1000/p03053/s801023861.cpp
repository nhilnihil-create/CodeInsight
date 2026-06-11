#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 1005;
queue<pair<P,int> > Q;
char a[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int main()
{
	int H,W;
	cin >> H >> W;
	rep(i,H)
	{
		rep(j,W)
		{
			cin >> a[i][j];
			if (a[i][j] == '#')
			{
				Q.push(make_pair(P(i,j),0));
			}
		}
	}
	int ans = 0;
	while(!Q.empty())
	{
		pair<P,int> p = Q.front();
		Q.pop();
		int pff = p.first.first, pfs = p.first.second, ps = p.second;
		if (visited[pff][pfs]) continue;
		ans = max(ans,ps);
		visited[pff][pfs] = true;
		//cout << "visiting:" << pff << " " << pfs << " " << ps << endl;
		rep(i,4)
		{
			int x1 = pff+dx[i], y1 = pfs+dy[i];
			if (x1 >= 0 && x1 < H && y1 >= 0 && y1 < W) Q.push(make_pair(P(x1,y1),ps+1));
		}
	}
	cout << ans << endl;
	return 0;
}