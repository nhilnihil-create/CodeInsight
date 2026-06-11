#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e6;
const int inf=1e9;
class union_find{//union by rank
public:
	vector<int> par;
	union_find(int n):par(n){
		rep(i,0,n) par[i]=i;
	}
	int root(int v){
		if(par[v]==v) return v;
		else{ par[v]=root(par[v]); return par[v]; }
	}
	void unite(int x,int y){
		int a=root(x);
		int b=root(y); 
		if(a!=b) par[a]=b;
		return;
	}
	bool same(int x,int y){
		return root(x)==root(y);
	}
};
int main(){
	int N,M;cin>>N>>M;
	union_find id(N),vl(N);
	int P[N];
	rep(i,0,N){ cin>>P[i]; P[i]--; }
	int x,y;
	rep(i,0,M){
		cin>>x>>y; x--; y--;
		id.unite(x,y);
		vl.unite(P[x],P[y]);
	}
	int cnt=0;
	rep(i,0,N){
		if(P[id.root(i)] == vl.root(i)) cnt++;
	}
	cout<<cnt<<endl;
}