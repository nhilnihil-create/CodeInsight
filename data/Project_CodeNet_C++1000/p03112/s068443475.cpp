#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,int> Pi;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define fi first
#define se second
#define endl "\n"

template<typename T> inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){
	int len=d.size();
	rep(i,len){
		s<<d[i];if(i<len-1) s<<" ";
	}
	return s;
}
template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){
	int len=d.size();
	rep(i,len){
		s<<d[i]<<endl;
	}
	return s;
}
template<typename T> ostream& operator<<(ostream& s,const set<T>& v){
	s<<"{ ";
	for(auto itr=v.begin();itr!=v.end();++itr) {
		if (itr!=v.begin()) {s<< ", ";}
		s<<(*itr);
	}
	s<<" }";
	return s;
}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){
	s<<"{"<<endl;
	for(auto itr=m.begin();itr!=m.end();++itr){
		s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;
	}
	s<<"}"<<endl;
	return s;
}

const ll mod=1e9+7;
const ll inf=1e17;
const int INF=1e9;
const double PI=acos(-1);
const double EPS=1e-10;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int a,b,q;
	cin>>a>>b>>q;
	vector<ll> s(a+1,-inf),t(b+1,-inf);
	rep(i,a) cin>>s[i+1];
	rep(i,b) cin>>t[i+1];
	while(q--){
		ll x;
		cin>>x;
		auto itr1=lower_bound(begin(s),end(s),x);
		ll A=*itr1;
		itr1--;
		ll B=*itr1;
		auto itr2=lower_bound(begin(t),end(t),x);
		ll C=*itr2;
		itr2--;
		ll D=*itr2;
		ll ans=inf;
		chmin(ans,abs(x-A)+abs(A-C));
		chmin(ans,abs(x-A)+abs(A-D));
		chmin(ans,abs(x-B)+abs(B-C));
		chmin(ans,abs(x-B)+abs(B-D));
		chmin(ans,abs(x-C)+abs(C-A));
		chmin(ans,abs(x-C)+abs(C-B));
		chmin(ans,abs(x-D)+abs(D-A));
		chmin(ans,abs(x-D)+abs(D-B));
		cout<<ans<<endl;
	}
}