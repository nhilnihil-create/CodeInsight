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
int L[111111],R[111111];

signed main(){
	cin>>N;
	rep(i,N)cin>>L[i]>>R[i];
	sort(L,L+N);reverse(L,L+N);

	sort(R,R+N);

	int ans=0;
	int sum=0;
	for(int i=0;i<N;i++){
		if(i==0||L[i]>R[0])chmax(ans,sum+L[i]*2);
		if(i==0||R[i]<L[0])chmax(ans,sum-R[i]*2);
		if(L[i]<R[i])continue;
		sum+=(L[i]-R[i])*2;
		chmax(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}