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
	ll n,k;
	cin>>n>>k;
	vector<P> g(n);
	rep(i,n){
		cin>>g[i].se>>g[i].fi;
	} 
	sort(begin(g),end(g),greater<Pi>());
	set<ll> cnt;
	priority_queue<ll,vector<ll>,greater<ll>> que1;
	priority_queue<ll> que2;
	ll ans=0;
	rep(i,k){
		if(cnt.count(g[i].se)){
			que1.push(g[i].fi);
		}
		ans+=g[i].fi;
		cnt.insert(g[i].se);
	}
	ll x=cnt.size();
	ans+=x*x;
	FOR(i,k,n){
		if(cnt.count(g[i].se)) continue;
		if(que2.size()>=que1.size()) break;
		que2.push(g[i].fi);
		cnt.insert(g[i].se);
	}
	ll now=ans;
	while(!que1.empty() && !que2.empty()){
		now=now-que1.top()+que2.top()+2*x+1;
		x++;
		que1.pop();
		que2.pop();
		chmax(ans,now);
	}
	cout<<ans<<endl;
}