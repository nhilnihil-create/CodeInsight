#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long int li;
#define mkp make_pair
#define sc(x) scanf("%lld",&x)
#define pf(x,y) printf("%lld %lld", x,y)
#define pfn printf("\n")
#define fr(i,a,n) for(i = a ; i < n ; i++)
map<long int , list<long int> > mp;
int vis[100001];
int dist[100001];
long int maxi = 0;
void dfs(long int src){
	vis[src] = 1;
//	cout << src << endl;
	for(auto i: mp[src]){
		if(!vis[i])dfs(i);
//		cout << i << " " << dist[i] << endl;
		dist[src] = max(dist[src],1+dist[i]);
	}
	if(maxi<dist[src])maxi=dist[src];
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long int n,m,x,y;
	cin >> n >> m;

	
	for(int i = 0 ; i < m ; i++){
		cin >> x >> y;
		mp[x].push_back(y);

	}

	for(long int i = 1 ; i <=n;i++){
		if(!vis[i])
			dfs(i);
	}
//	for(int i = 1 ; i<=n;i++){
////		cout << ind[i].first << " " << ind[i].second <<endl;
//		cout << dist[i] << " ";
//	}
	cout << maxi<< endl;
	return 0;
}
