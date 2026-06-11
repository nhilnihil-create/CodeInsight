/*
ID: Barry Wang
LANG: C++11
TASK: 
*/
#include <bits/stdc++.h>
using namespace std;
/*---define tricks---*/
#define ALL(v) v.begin(),v.end()
#define UN(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())
#define FILL(x,y) memset(x,y,sizeof(x))
#define EACH(v,it) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define revsort(b,e) sort(b,e),reverse(b,e)
#define X first
#define Y second
#define Chtolly return 0
/*---define types---*/
typedef long long ll;
typedef list<int> li;
typedef queue<int> qi;
typedef deque<int> dqi;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef unsigned int uint;
/*---define variables---*/
const int inf=(1<<29);
int k; 
int cnt;
int head[1000005],from[1000005],to[1000005],nxt[1000005],val[1000005];
bool vis[1000005];
int dis[1000005];
queue<int> q;
/*---define function---*/

void add(int x,int y,int w){
	from[++cnt]=x;
	to[cnt]=y;
	val[cnt]=w;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

void BFS(){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	vis[1]=1;
	q.push(1);
	while(!q.empty()){
		int x=q.front();
		q.pop(); 
		vis[x]=0;
		for(int i=head[x];i;i=nxt[i]){
			int y=to[i];
			if(dis[y]>dis[x]+val[i]){
				dis[y]=dis[x]+val[i];
				if(!vis[y]){
					vis[y]=1;
					q.push(y);
				}
			}
		}
	}
}

/*---main code---*/
int main(){
	FIO;
	cin>>k;
	for(int i=0;i<k;++i){
		int x=i,y=(i+1)%k,yy=(i*10)%k;
		add(x,y,1);
		add(x,yy,0);
	}
	BFS();
	cout<<dis[0]+1<<'\n';
	return 0;
}
