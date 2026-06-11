#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int dx[]={-1,1,0,0};
const int dy[]={0,0,1,-1};
const int MAX_N =1002;
int H, W;
string g[MAX_N];
bool vis[MAX_N][MAX_N];

void solve()
{
	queue<pair<pair<int,int>,int>> que;
	for(int i=0;i<H;++i)for(int j=0;j<W;++j){
		if(g[i][j] == '#'){
			que.emplace(make_pair(i,j), 0);
			vis[i][j]=true;
		}
	}
	int ans = 0;
	while(!que.empty()){
		auto cur=que.front(); que.pop();
		int x = cur.first.first, y = cur.first.second;
		int z = cur.second;
		ans = max(ans, z);
		for(int i=0;i<4;++i){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx>=0&&nx<H&&ny>=0&&ny<W&&!vis[nx][ny]){
			    vis[nx][ny]=true;
				que.emplace(make_pair(nx,ny), z+1);
			}
		}
	}
	cout << ans << '\n';
}

int main()
{	
	cin >> H >> W;
	for(int i=0;i<H;++i){
		cin >> g[i];
	}
	solve();
	return 0;
}