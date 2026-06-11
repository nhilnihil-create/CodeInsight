#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define Graph vector<vector<ll>>
constexpr ll INF=(1ll<<60);
constexpr ll mod=1000000007;
constexpr double pi=3.14159265358979323846;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
	ll n;cin>>n;
	vector<ll> x(n),ins(n);
	rep(i,n){
		cin>>x[i];
		ins[i]=x[i];
	}
	sort(ins.begin(),ins.end());

	double mid=(ins[n/2-1]+ins[n/2])/2;//真の中央値
	ll mid1=ins[n/2];
	ll mid2=ins[n/2-1];

	rep(i,n){
		if(mid-x[i]>=0.0) cout<<mid1<<endl;
		else cout<<mid2<<endl;
	}

    return 0;
}