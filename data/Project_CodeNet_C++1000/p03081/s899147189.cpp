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

int N,Q;
string S;
char T[222222],D[222222];

int fall(int x){
	rep(i,Q){
		if(T[i]!=S[x])continue;
		if(D[i]=='L')x--;
		else x++;
		if(x<0)return -1;
		if(x>=N)return 1;
	}
	return 0;
}

signed main(){
	cin>>N>>Q;
	cin>>S;
	rep(i,Q)cin>>T[i]>>D[i];

	int lb=-1,ub=N;
	while(ub-lb>1){
		int mid=(ub+lb)/2;
		if(fall(mid)==-1)lb=mid;
		else ub=mid;
	}

	int ans=lb+1;

	lb=-1;
	ub=N;
	while(ub-lb>1){
		int mid=(ub+lb)/2;
		if(fall(mid)==1)ub=mid;
		else lb=mid;
	}
	ans+=N-ub;
	cout<<N-ans<<endl;
	return 0;
}