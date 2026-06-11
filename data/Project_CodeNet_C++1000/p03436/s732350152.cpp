#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using ll = long long;

using namespace std;

ll mod=1e9+7;


int main() {
	int h,w;
	cin>>h>>w;
	vector<vector<char>>map(h,vector<char>(w));
	int ans=h*w-2;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>map[i][j];
			if(map[i][j]=='#'){
				ans--;
			}
		}
	}
	int dx[]={1,0,-1,0};
	int dy[]={0,1,0,-1};
	queue<pair<pair<int,int>,int>>todo;
	todo.push(pair<pair<int,int>,int>(pair<int,int>(0,0),0));
	bool ok=false;
	while(todo.empty()!=1){
		auto tmp=todo.front();
		todo.pop();
		int x=tmp.first.first;
		int y=tmp.first.second;
		int depth=tmp.second;
		bool flag=false;
		for(int j=0;j<4;j++){
			int nx=x+dx[j];
			int ny=y+dy[j];
			if(nx<0||nx>=h||ny<0||ny>=w)continue;
			if(nx==h-1&&ny==w-1){
				ok=true;
				ans-=depth;
				flag=true;
				break;
			}
			if(map[nx][ny]!='#'){
				todo.push(pair<pair<int,int>,int>(pair<int,int>(nx,ny),depth+1));
				map[nx][ny]='#';
			}
		}
		if(flag)break;
	}
	if(!ok)ans=-1;
	cout<<ans<<endl;
	return 0;
}