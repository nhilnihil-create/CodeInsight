#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long



using namespace std;

void file(){
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
}
int tc;
const int N=5e5+5,M=2e6+5,MOD=1e9+7,OO=1e9;
int g[205][205];
int n,m,k;
int dist[205][205];
set<int>wa[205];
void dij(int x){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	for(int i=1;i<=n;i++)dist[x][i]=1e9;
	dist[x][x]=0;
	q.push({0,x});
	while(!q.empty()){
		auto p = q.top();
		q.pop();
		int u = p.second , cst = p.first;
		for(auto i : wa[u]){
			int v = i;
			int w = g[u][v];
			if(cst + w < dist[x][v]){
				dist[x][v] = cst+w;
				q.push({dist[x][v],v});
			}

		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();	
 	
 	scanf("%d %d",&n,&k);

 	std::vector<int> x(n),y(n);

 	for(int i=0;i<n;i++)scanf("%d %d",&x[i],&y[i]);
 	ll ans = 5e18;
 	for(auto x1 : x){
 		for(auto x2:x){
 			if(x2<x1)continue;
 			for(auto y1:y){
 				for(auto y2:y){
 					if(y2<y1)continue;
 					int cnt = 0;
 					for(int i=0;i<n;i++){
 						if(x[i]>=x1 && x[i]<=x2 && y[i]>=y1 && y[i]<=y2)cnt++;
 					}
 					if(cnt>=k){
 						ans = min(ans,(ll)(x2-x1)*(y2-y1));
 					}
 				}
 			}
 		}
 	}
 	printf("%lld\n",ans );
}		
