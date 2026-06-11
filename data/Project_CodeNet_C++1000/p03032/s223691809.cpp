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

const ll mod=1'000'000'007;
const ll inf=1'000'000'000'000'000'00;
const int INF=1'000'000'000;
const double EPS=1e-10;
const double PI=acos(-1);

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	ll n,k;
	cin>>n>>k;
	vector<ll> v(n);
	rep(i,n){
		cin>>v[i];
	}
	ll ans=0;
	rep(l,n+1)rep(r,n+1){
		if(l+r>k || l-1>=n-r) continue;
		vector<ll> now;
		rep(i,l) now.push_back(v[i]);
		for(int i=n-1;i>=n-r;i--) now.push_back(v[i]);
		sort(begin(now),end(now),greater<ll>());
		ll ret=k-(l+r),sum=0;
		while(ret && now.size()){
			if(now.back()<0){
				ret--;
				now.pop_back();
			}else{
				break;
			}
		}
		for(auto x:now) sum+=x;
		chmax(ans,sum);
	}
	cout<<ans<<endl;
}