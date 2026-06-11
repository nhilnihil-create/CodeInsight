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
int main(){
	int Q;
	cin>>Q;
	vector<ll> X(Q),Y(Q);
	rep(q,Q){
		ll x,y;
		cin>>x>>y;
		X[q] = x+y;
		Y[q] = x-y;
	}
	rep(q,Q){
		if((X[0]+X[q])%2 != 0){
			puts("-1");
			return 0;
		}
	}
	bool xinc = false;
	if(X[0]%2 == 0){
		rep(q,Q) X[q]++,Y[q]++;
		xinc = true;
	}
	int N = 32;
	if(xinc){
		cout<<N+1<<endl;
		cout<<1<<" ";
	}else{
		cout<<N<<endl;
	}
	rep(i,N) cout<<(1LL<<i)<<" ";
	puts("");
	rep(q,Q){
		vector<int> v(N);
		rep(t,2){
			ll inc = ((t==0 ? X[q] : Y[q]) + ((1LL<<N)-1)) / 2;
			rep(i,N) if((inc>>i)&1) v[i] |= 1<<t;
		}
		if(xinc) cout<<"L";
		rep(i,N) cout<<"LUDR"[v[i]];
		puts("");
	}
}