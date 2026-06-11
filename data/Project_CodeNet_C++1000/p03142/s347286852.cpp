#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 50;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
using namespace std;

vector<vector<int>>g;
vector<int>cost,par;


void solve(){
	int n,m;
	cin>>n>>m;
	cost.resize(n,0);
	par.resize(n);
	g.resize(n);
	map<int,int>r;
	int root;
	rep(i,n+m-1){
		int a,b;
		cin>>a>>b;
		a--;b--;
		r[b]++;
		g[a].pb(b);
	}
	for(int i=0;i<n;++i){
		if(!r[i])root=i;
	}
	par[root]=root;
	stack<int>q;
	q.push(root);
	while(!q.empty()){//子孫の計算が終わっていない状態で探索を開始するとやり直しになり、TLEになる。
		int v=q.top();
		q.pop();
		for(int x:g[v]){
			r[x]--;
			if(chmax(cost[x],cost[v]+1))par[x]=v+1;
			if(!r[x])q.push(x);
		}
	}
	for(int i=0;i<n;++i){
		if(i==root)cout<<0<<"\n";
		else cout<<par[i]<<"\n";
	}
}

signed main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	solve();
	return 0;
}
