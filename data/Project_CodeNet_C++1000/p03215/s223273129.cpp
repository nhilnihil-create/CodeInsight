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

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
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
template<typename T> ostream& operator<<(ostream& s,const multiset<T>& v){
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
const ll inf=1e15;
const int INF=1e9;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	vector<ll> a(n+1),sum(n+1,0);
	multiset<ll> beauty;
	FOR(i,1,n+1){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	FOR(l,1,n+1)FOR(r,l,n+1){
		beauty.insert(sum[r]-sum[l-1]);
	}
	for(ll i=60;i>=0;i--){
		ll cnt=0;
		for(auto itr:beauty){
			if(1ll<<i & itr){
				cnt++;
			}
		}
		if(cnt>=k){
			multiset<ll> nb;
			for(auto itr:beauty){
				if(1ll<<i & itr){
					nb.insert(itr);
				}
			}
			swap(beauty,nb);
		}
	}
	ll ans=(1ll<<60)-1;
	for(auto itr:beauty){
		ans&=itr;
	}
	cout<<ans<<endl;
}