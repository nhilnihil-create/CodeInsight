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

int N,M,ne[111111],ans=0;

int root(int x){
	if(ne[x]==x)return x;
	return ne[x]=root(ne[x]);
}
bool same(int x,int y){return root(x)==root(y);}
void unite(int x,int y){
	if(same(x,y))return;
	N--;
	x=root(x),y=root(y);
	ne[x]=y;
	return;
}

int main() {
	cin>>N>>M;
	for(int i=1;i<=N;i++)ne[i]=i;
	for(int i=0;i<M;i++){
		int x,y,z;
		cin>>x>>y>>z;
		unite(x,y);
	}
	cout<<N<<endl;
	return 0;
}

