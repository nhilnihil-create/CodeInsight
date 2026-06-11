#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

const int N=100010;
int n,m;
vector<int>g[N];
int in[N],len[N];

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int u,v;cin>>u>>v;--u;--v;
		g[u].push_back(v);
		++in[v];
	}
	queue<int>q;
	for(int i=0;i<n;++i)if(!in[i])q.push(i);
	int res=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto v:g[u]){
			len[v]=max(len[v],len[u]+1);
			if(!--in[v])q.push(v);
		}
		res=max(res,len[u]);
	}
	cout<<res<<endl;
}
