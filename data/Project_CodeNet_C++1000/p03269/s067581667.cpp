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
	int L;
	cin>>L;
	int N = 20;
	using E = tuple<int,int,int>;

	vector<E> es;
	rep(i,N-2){
		es.pb(E{i,i+1,0});
		es.pb(E{i,i+1,1<<i});
	}
	int off = 0;
	for(int i=N-2;i>=0;i--){
		while(L>=(1<<i)){
			es.pb(E{i,N-1,off});
			L -= 1<<i;
			off += 1<<i;
		}
	}
	cout<<N<<" "<<es.size()<<endl;
	for(E e: es){
		int x,y,w;
		tie(x,y,w) = e;
		cout<<x+1<<" "<<y+1<<" "<<w<<endl;
	}
}