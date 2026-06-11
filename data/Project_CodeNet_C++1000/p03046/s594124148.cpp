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

signed main(){
	int M,K;
	cin>>M>>K;
	if((1<<M)<=K){
		cout<<-1<<endl;
		return 0;
	}

	if(M==1){
		if(K==0){
			cout<<"0 0 1 1"<<endl;
		}
		else{
			cout<<-1<<endl;
		}
		return 0;
	}

	vint ans;
	for(int i=(1<<M)-1;i>=0;i--){
		if(i==K)continue;
		ans.pb(i);
	}
	ans.pb(K);
	for(int i=0;i<(1<<M);i++){
		if(i==K)continue;
		ans.pb(i);
	}
	ans.pb(K);
	rep(i,ans.size()){
		if(i)cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}