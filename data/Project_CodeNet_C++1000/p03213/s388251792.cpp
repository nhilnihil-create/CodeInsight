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
template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){s<<"{"<<endl;for(auto itr=m.begin();itr!=m.end();++itr){s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;}s<<"}"<<endl;return s;}

const ll mod=1e9+7;
const ll inf=1e17;
const int INF=1e9;
const double PI=acos(-1);
const double EPS=1e-10;

map<ll,ll> mp;

//素因数分解
template <class T>
void prime_factor(T x){
	for(T i=2;i*i<=x;i++){
		while(x%i==0){
			x/=i;
			mp[i]++;
		}
	}
	if (x!=1){
		mp[x]++;
	}
}

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	FOR(i,1,n+1){
		prime_factor(i);
	}
	ll ans=0;
	vector<ll> cnt(5,0);
	for(auto itr:mp){
		if(itr.se>=74){
			rep(i,5) cnt[i]++;
		}else if(itr.se>=24){
			FOR(i,1,5) cnt[i]++;
		}else if(itr.se>=14){
			FOR(i,2,5) cnt[i]++;
		}else if(itr.se>=4){
			FOR(i,3,5) cnt[i]++;
		}else if(itr.se>=2){
			FOR(i,4,5) cnt[i]++;
		}
	}
	//^74
	ans+=cnt[0];
	//^24*^2
	ans+=cnt[1]*(cnt[4]-1);
	//^14*^4
	ans+=cnt[2]*(cnt[3]-1);
	//^4*^4*^2
	ans+=cnt[3]*(cnt[3]-1)*(cnt[4]-2)/2;
	cout<<ans<<endl;
}