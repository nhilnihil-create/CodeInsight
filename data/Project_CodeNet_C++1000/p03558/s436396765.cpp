#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 1e6+23;
vector<pii> g[maxn];
int n,s;
int d[maxn];
bool vis[maxn];
priority_queue<pair<int,int>> q;
void dij(int s)
{
    memset(d,0x3f,sizeof(d));
    memset(vis,false,sizeof(vis));
    q.push({0,s});d[s]=0;
    while(!q.empty()){
        int x=q.top().second;q.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(pii t:g[x]){
        	int y=t.first;
        	int z=t.second;
        	if(d[y]>d[x]+z){
                d[y]=d[x]+z;
                q.push({-d[y],y});
            }
        }
    }
}


int main(){
	cin>>n;
	s=n;
	for(int i=1;i<9;i++) g[s].push_back({i,i});
	for(int i=1;i<n;i++){
		int k=i*10;
		for(int j=0;j<10;j++){
			g[i].push_back({(k+j)%n,j});
		}
	}
	dij(s);
	cout<<d[0];
}
