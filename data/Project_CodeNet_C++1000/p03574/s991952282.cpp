#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

string s[100];
int main(){
	int h,w;scanf("%d%d",&h,&w);
	rep(i,h)cin>>s[i];
	rep(i,h)rep(j,w){
		if(s[i][j]=='#')continue;
		s[i][j]='0';
		for(int dx=-1;dx<=1;dx++){
			for(int dy=-1;dy<=1;dy++){
				int nx=i+dx,ny=j+dy;
				if(0<=nx&&nx<h&&0<=ny&&ny<w){
					if(s[nx][ny]=='#')s[i][j]++;
				}
			}
		}
	}
	rep(i,h)cout<<s[i]<<endl;
}
