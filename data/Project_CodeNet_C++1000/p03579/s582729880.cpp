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

int N=100010;
int n;
vector<vector<int>> g(N);
vector<int> color(N,0);

bool dfs(int v,int c){
	color[v]=c;
	for(auto itr:g[v]){
		if(color[itr]==c) return false;
		if(color[itr]==0 && !dfs(itr,-c)) return false;
	}
	return true;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int m;
	cin>>n>>m;
	rep(i,m){
		int a,b;
		cin>>a>>b;
		a--,b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	if(m<=2){
		cout<<0<<endl;
		return 0;
	}
	if(dfs(0,1)){
		int cnt=0;
		rep(i,n){
			if(color[i]==1) cnt++;
		}
		cout<<(ll)cnt*(ll)(n-cnt)-m<<endl;
	}else{
		cout<<ll(n)*ll(n-1)/2-m<<endl;
	}
}