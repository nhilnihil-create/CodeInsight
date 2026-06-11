/*
AtCoder AGC 033 Task C

Takahashi and Aoki will play a game on a tree. 
The tree has N vertices numbered 1 to N, and the i-th of the N edges connects Vertex ai and Vertex bi At the beginning of the game, 
each vertex contains a coin. 
 Starting from Takahashi, he and Aoki will alternately perform the following operation:
1.Choose a vertex v that contains one or more coins, and remove all the coins from v.
2.Then, move each coin remaining on the tree to the vertex that is nearest to v among the adjacent vertices of the coin's current vertex.
The player who becomes unable to play, loses the game. 
That is, the player who takes his turn when there is no coin remaining on the tree, loses the game. 
Determine the winner of the game when both players play optimally.

Input:
a1 b1
a2 b2
.
.
.
aN-1 bN-1

Output:
Print 'First' if Takahashi will win, and print 'Second' if Aoki will win.

*/

#include<bits/stdc++.h>
using namespace std;

int head[200010],o=0,di=-1,ans=0,n;
bool vis[200010];
struct edge{
	int to,link;
}e[400010];

void add_edge(int u,int v){
	e[++o].link=head[u],e[o].to=v,head[u]=o;
	e[++o].link=head[v],e[o].to=u,head[v]=o;
}

void dfs(int u,int d,bool k){
	vis[u]=k;
	if(ans<d){
		ans=d;
		di=u;
	}
	for(int i=head[u];i;i=e[i].link){
		if(vis[e[i].to]!=k) dfs(e[i].to,d+1,k);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)
		scanf("%d %d",&u,&v),add_edge(u,v);
	dfs(1,1,1);
	dfs(di,1,0);
	if(ans%3==2)
		printf("Second\n");
	else
		printf("First\n");
}
