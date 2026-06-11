#include<iostream>
#include<iomanip>
#include<functional>
#include<algorithm>
#include<string>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<set>
#include<queue>
#include<cmath>

using namespace std;
#define LL long long

int N,M,p[111111],ans=0;

struct UnionFind{
	int size;
	vector<int>ne;
	void init(int n){
		size=n;
		for(int i=0;i<=size;i++)ne.push_back(i);
		return;
	}
	
	int root(int x){
		if(ne[x]==x)return x;
		return ne[x]=root(ne[x]);
	}

	bool same(int x,int y){return root(x)==root(y);}

	void unite(int x,int y){
		if(same(x,y))return;
		int X=root(x),Y=root(y);
		ne[X]=Y;
		return;
	}

};
UnionFind u;

int main() {
	cin>>N>>M;
	u.init(N);
	for(int i=0;i<N;i++)cin>>p[i];
	for(int i=0;i<M;i++){
		int x,y;
		cin>>x>>y;
		u.unite(x,y);
	}
	for(int i=0;i<N;i++){
		if(u.root(p[i])==u.root(i+1))ans++;
	}
	cout<<ans<<endl;
	return 0;
}

