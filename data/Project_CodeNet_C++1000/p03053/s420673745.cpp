#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> P;
const int INF=100000000;

int dis[1010][1010];
int dh[4]={1,0,-1,0},dw[4]={0,1,0,-1};
queue<P> que;
int main(){
	int H,W;
	int ans=0;
	cin>>H>>W;	
	
        for(int i=0;i<H;i++)
	{
		string s;
		cin>>s;
		for(int j=0;j<W;j++)
		{
			dis[i][j]=INF;
			if(s[j]=='#')
			{
				que.push(P(i,j));
				dis[i][j]=0;
			}
		}
	}
	
	while(que.size())
	{
		P p=que.front();
		que.pop();
		
		for(int i=0;i<4;i++)
		{
			int nh=p.first+dh[i],nw=p.second+dw[i];
			if(0<=nh && nh<H && 0<=nw && nw<W && dis[nh][nw]==INF)
			{
				que.push(P(nh,nw));
				dis[nh][nw]=dis[p.first][p.second]+1;
				ans=max(ans,dis[nh][nw]);
			}
		}	
	}
	
	cout<<ans<<endl;
	return 0;
}