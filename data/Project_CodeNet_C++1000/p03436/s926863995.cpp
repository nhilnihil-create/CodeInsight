#include <bits/stdc++.h>
using namespace std;

int main(){
	int h,w;
    cin >> h >> w;
	char c[51][51];
	int check[51][51];
	queue<pair<int,int>> que;
    int i,j;
    int ans=0;
    for(i=1;i<h+1;i++)for(j=1;j<w+1;j++){cin >> c[i][j]; check[i][j]=1e9; if(c[i][j]=='#')ans++;}
    for(i=1;i<h+1;i++)c[i][0]='#';
    for(j=1;j<w+1;j++)c[0][j]='#';
	check[1][1]=1;
    que.push(pair<int,int> (1,1));
	while(!que.empty()){
		int x = que.front().first;
		int y = que.front().second;
		int dx[4] = {1,-1,0,0};
		int dy[4] = {0,0,1,-1};
		que.pop();
		for(i=0;i<4;i++){
			if(c[x+dx[i]][y+dy[i]]=='.' && check[x+dx[i]][y+dy[i]]>check[x][y]+1){
				check[x+dx[i]][y+dy[i]]=check[x][y]+1;
				que.push(pair<int,int> (x+dx[i],y+dy[i]));
			}
		}
	}
    if(check[h][w]==1e9)cout << -1 << endl;
    else cout << h*w-check[h][w]-ans << endl;
}