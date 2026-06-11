#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << (x) << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
int N;
vector<ll> D;
int main(){
	cin>>N;
	D.resize(N);
	rep(i,N) cin>>D[i];
	using ll_i = pair<ll,int>;
	vector<ll_i> dis;
	map<ll,int> mp;
	rep(i,N){
		dis.pb(ll_i(D[i],i));
		mp[D[i]] = i;
	}
	sort(all(dis),greater<ll_i>());
	using P = pair<int,int>;
	vector<P> es;
	vector<int> sz(N);
	vector<ll> dsum(N);
	rep(_,N-1){
		int v = dis[_].sc;
		sz[v]++;
		ll tar = D[v] - (N-2*sz[v]);
		if(!mp.count(tar)){
			puts("-1");
			return 0;
		}
		int p = mp[tar];
		sz[p] += sz[v];
		dsum[p] += dsum[v] + sz[v];
		es.pb(P(v,p));
	}
	{
		int r = dis[N-1].sc;
		if(dsum[r] != D[r]){
			puts("-1");
			return 0;
		}
	}
	for(P p: es){
		cout<<p.fs+1<<" "<<p.sc+1<<endl;
	}
}