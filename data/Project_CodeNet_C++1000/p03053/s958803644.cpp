#include <bits/stdc++.h>
using namespace std;
char aa[1005][1005];
int dist[1005][1005];
vector<int> dx={1,0,0,-1};
vector<int> dy={0,1,-1,0};
int main() {
	int h,w;
	cin >> h >> w;
	queue<pair<int,int>> que;
	pair<int,int> a;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin >> aa[i][j];
			if(aa[i][j]=='.')dist[i][j]=-1;
			else{
				dist[i][j]=0;
				a.first=i;
				a.second=j;
				que.push(a);
			}
		}
	}
	while(!que.empty()){
		pair<int,int> v;
		v=que.front();
		que.pop();
		for(int i=0;i<4;i++){
			int nx=v.first+dx[i];
			int ny=v.second+dy[i];
			if(nx<0||nx>=h||ny<0||ny>=w) continue;
			if(dist[nx][ny]!=-1) continue;
			dist[nx][ny]=dist[v.first][v.second]+1;
			pair<int,int> nv;
			nv.first=nx;
			nv.second=ny;
			que.push(nv);
		}
	}
	int ans=0;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			ans=max(ans,dist[i][j]);
		}
	}
	cout << ans << endl;
}
