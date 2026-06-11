#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,int> Pi;
#define rep(i,n) for(ll i=0;i<n;i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define fi first
#define se second
#define endl "\n"

template<typename T> inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){int len=d.size();rep(i,len){s<<d[i];if(i<len-1) s<<" ";}return s;}
template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){int len=d.size();rep(i,len){s<<d[i]<<endl;}return s;}
template<typename T> ostream& operator<<(ostream& s,const set<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T> ostream& operator<<(ostream& s,const multiset<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){s<<"{"<<endl;for(auto itr=m.begin();itr!=m.end();++itr){s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;}s<<"}"<<endl;return s;}

const ll mod=1e9+7;
const ll inf=1e17;
const int INF=1e9;
const double EPS=1e-10;
const double PI=acos(-1);

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	ll n,k;
	cin>>n>>k;
	vector<P> g(n);
	rep(i,n){
		cin>>g[i].fi>>g[i].se;
	}
	sort(begin(g),end(g),[](const P &a,const P &b){
		return a.se>b.se;
	});
	ll ans=0;
	map<ll,ll> mp;
	rep(i,k){
		ans+=g[i].se;
		mp[g[i].fi]++;
	}
	priority_queue<P,vector<P>,greater<P>> que;//(美味しさ,ネタ)
	rep(i,k){
		if(mp[g[i].fi]>=2){
			que.push({g[i].se,g[i].fi});
		}
	}
	ans+=(ll)mp.size()*(ll)mp.size();
	ll now=ans;
	FOR(i,k,n){//美味しさを引き換えに種類数を増やしていく
		if(mp.count(g[i].fi)) continue;//既に含まれていたら選ぶ意味なし
		bool flag=false;
		while(!que.empty()){
			auto hoge=que.top();
			que.pop();
			if(mp[hoge.se]==1) continue;
			now-=hoge.fi;
			now+=g[i].se;
			mp[hoge.se]--;
			mp[g[i].fi]++;
			flag=true;
			break;
		}
		if(flag) now+=(ll)mp.size()*(ll)mp.size()-((ll)mp.size()-1)*((ll)mp.size()-1);
		chmax(ans,now);
	}
	cout<<ans<<endl;
}