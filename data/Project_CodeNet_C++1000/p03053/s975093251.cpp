#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <iomanip>
using namespace std;
int h,w;
char a[1000][1000];
bool b[1000][1000]={};
int d[1000][1000]={};
int main(){
	cin>>h>>w;
	queue<pair<int,int> > que;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>a[i][j];
			if(a[i][j]=='#'){
				que.push(make_pair(i,j));
				b[i][j]=1;
				d[i][j]=0;
			}
		}
	}
	int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
	while(!que.empty()){
		pair<int,int> now=que.front();
		int x=now.first;
		int y=now.second;
		que.pop();
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(0<=nx&&nx<h&&0<=ny&&ny<w&&!b[nx][ny]){
				b[nx][ny]=1;
				d[nx][ny]=d[x][y]+1;
				que.push(make_pair(nx,ny));
			}
		}
	}
	int ans=0;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			ans=max(ans,d[i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
