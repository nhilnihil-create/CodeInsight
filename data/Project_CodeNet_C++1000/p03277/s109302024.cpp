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
struct BIT{
	using D = int;
	int N;
	vector<D> bit;
	BIT(int n){		//nは区間幅!!!
		N=n;
		bit.assign(n+1,0);
	}
	BIT(){}
	D sum(int i){		//i個の和a[0]+..a[i-1]
		D s=0;
		while(i>0){
			s+=bit[i];
			i-=(i&-i);
		}
		return s;
	}
	D val(int i){	//return a[i]	(0-ind)
		return sum(i+1)-sum(i);
	}
	void add(int i,D x){	//a[i]+=x (0-indexed)
		i++;
		while(i<=N){
			bit[i]+=x;
			i+=(i&-i);
		}
	}
};

bool is(V<bool> v){
	int N = v.size();
	BIT bit(2*N+1);	//[-N,N]
	int s = 0;
	ll cnt = 0;
	rep(i,N){
		bit.add(s+N,1);
		if(v[i]) s++;
		else s--;
		cnt += bit.sum(s+N+1);
	}
	return cnt >= ((ll)N*(N+1)/2+1)/2;
}
int main(){
	int N;
	cin>>N;
	V<int> a(N);
	rep(i,N) cin>>a[i];
	int lb = 1, ub = 1e9+1;
	while(ub-lb>1){
		int m = (ub+lb)/2;
		V<bool> v(N);
		rep(i,N) v[i] = a[i]>=m;
		if(is(v)) lb = m;
		else ub = m;
	}
	cout<<lb<<endl;
}