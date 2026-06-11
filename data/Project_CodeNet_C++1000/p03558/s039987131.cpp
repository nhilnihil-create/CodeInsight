#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int K;
vector<pair<int,int>> g[2][size];
int d[2][size];
void dijkstra(int id,int a){// O(NlogN+M)
	priority_queue<pair<long,int>> pq;
	rep(i,0,K){ d[id][i] = inf; pq.push({-d[id][i],i}); }
	d[id][a] = 0; pq.push({0,a});
	int v; long temp;
	while(!pq.empty()){
		v = pq.top().second;
		pq.pop();
        int u;
		for(pair<int,long> p:g[id][v]){
            u = p.first;
			temp = d[id][v] + p.second;
			if(d[id][u] > temp){
				d[id][u] = temp;
				pq.push({-d[id][u],u});
			}
		}
	}return;
}
int main(){
	cin>>K;
	rep(i,0,K)rep(j,0,10){
		int t = (10*i + j) % K;
		g[0][i].push_back({t,j});
		g[1][t].push_back({i,j});
	}
	dijkstra(0,0);
	dijkstra(1,0);
	int ans = inf;
	rep(i,1,K) ans = min(ans , d[0][i] + d[1][i]);
	cout<<ans<<endl;
}