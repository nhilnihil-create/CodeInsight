#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue> 
#include <map>
#include <cmath> 
#include <stack>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
struct node{
	int id,w;
	bool operator<(const node &n1)const{
		return w>n1.w;
	}
	node(int id=0,int w=0):id(id),w(w){}
};
priority_queue<node> q;
int n;
int d[maxn];
bool vis[maxn];
vector<pair<int,int> > adj[maxn];
int main(){
	cin>>n;
	for (int i=1;i<n;i++){
		adj[i].push_back(make_pair((i+1)%n,1));
		adj[i].push_back(make_pair(i*10%n,0));
	}
	memset(d,0x3f,sizeof(d));
	d[1]=1;
	q.push(node(1,1));
	while(!q.empty()){
		int u=q.top().id;
		q.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (int i=0;i<adj[u].size();i++){
			int v=adj[u][i].first;
			int w=adj[u][i].second;
			if (d[v]>d[u]+w){
				d[v]=d[u]+w;
				q.push(node(v,d[v]));
			}
		}
	}
	cout<<d[0]<<endl;
}