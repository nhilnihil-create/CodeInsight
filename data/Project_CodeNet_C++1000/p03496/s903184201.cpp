#include<bits/stdc++.h>

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)a, i##_len=(b); i<i##_len; i++)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

#define int long long

using namespace std;

using P = pair<int, int>;
using ll = long long;

const long long INF = LLONG_MAX/3;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

struct UnionFind{
	std::vector<int> par,siz;
	void init(int n){
		par.resize(n);
		for(int i=0;i<n;i++)par[i]=i;
		siz.resize(n,1);
	}
	UnionFind(int n){
		init(n);
	}
	int root(int n){
		if(par[n]==n)return n;
		else return par[n]=root(par[n]);
	}
	bool issame(int x,int y){
		return (root(x)==root(y));
	}
	bool marge(int a,int b){
		if(issame(a,b))return false;
		else{
			a=root(a),b=root(b);
			if(siz[a]<siz[b])swap(a,b);
			siz[a]+=siz[b];
			par[a]=par[b];
			return true;
		}
	}
	int size(int n){
		return siz[root(n)];
	}
};

long long gcd(long long a,long long b){
    if(b==0)return a;
    return gcd(b,a%b);
}
long long lcm(long long i,long long j){
    return i*(j/gcd(i,j));
}

signed main(){
	int n;
	cin>>n;
	int a[100];
	rep(i,n)cin>>a[i];
	int m=0;
	int index=1;
	rep(i,n){
		if(abs(a[i])>=m){
			m=abs(a[i]);
			index=i;
		}
	}
	int cnt=0;
	vector<pair<int,int>> ans;
	rep(i,n){
		a[i]+=a[index];
		ans.push_back(make_pair(index,i));
		cnt++;
	}
	if(a[index]>=0){
		rep(i,1,n){
			a[i]+=a[i-1];
			ans.push_back(make_pair(i-1,i));
			cnt++;
		}
	}else{
		for(int i=n-2;i>=0;i--){
			a[i]+=a[i+1];
			ans.push_back(make_pair(i+1,i));
			cnt++;
		}
	}
	cout<<cnt<<endl;
	rep(i,ans.size()){
		cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
	}
	rep(i,n)cerr<<a[i]<<" ";
	cerr<<endl;
}