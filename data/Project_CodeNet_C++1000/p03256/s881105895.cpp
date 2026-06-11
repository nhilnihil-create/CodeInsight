#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=a;i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,m;cin>>n>>m;
	string s;cin>>s;
	vvc<int> g(n);
	rep(_,m){
		int a,b;cin>>a>>b;
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	vc<array<int,2>> d(n);
	rep(i,n){
		for(auto j:g[i])
			d[i][s[j]-'A']++;
	}
	int rem=n;
	queue<int> q;
	rep(i,n){
		if(!d[i][0]||!d[i][1])
			q.push(i);
	}
	while(q.size()){
		int v=q.front();q.pop();
		rem--;
		int k=s[v]-'A';
		for(auto f:g[v]){
			if(--d[f][k]==0&&d[f][k^1])
				q.push(f);
		}
	}
	
	cout<<(rem?"Yes":"No")<<endl;
}
