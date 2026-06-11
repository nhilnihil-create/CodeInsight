#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
	ost<<"{"<<p.first<<","<<p.second<<"}";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
	ost<<"{";
	for(int i=0;i<v.size();i++){
		if(i)ost<<",";
		ost<<v[i];
	}
	ost<<"}";
	return ost;
}

int N;
vint G[111111];
int C[111111];

int ans[111111];
void dfs(int v,int p,int &t){
	ans[v]=C[t++];
	for(auto u:G[v]){
		if(u==p)continue;
		dfs(u,v,t);
	}
}

signed main(){
	cin>>N;
	rep(i,N-1){
		int a,b;
		cin>>a>>b;
		a--;b--;
		G[a].pb(b);G[b].pb(a);
	}

	rep(i,N)cin>>C[i];
	sort(C,C+N);reverse(C,C+N);
	int t=0;
	dfs(0,-1,t);

	cout<<accumulate(C+1,C+N,0ll)<<endl;
	rep(i,N){
		if(i)cout<<" ";
		cout<<ans[i];
	}cout<<endl;
	return 0;
}