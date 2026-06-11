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
#define PI (acos(-1))

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
	int n;
	cin>>n;
	vector<ll> a(n+1),sum(n+1,0),f(n+1),g(n+1);
	FOR(i,1,n+1){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	ll l=1;
	ll p,q,R,S,mi;
	f[2]=1;
	FOR(r,3,n-1){
		p=sum[l],q=sum[r]-sum[l],mi=abs(p-q);
		l++;
		while(l<r){
			p=sum[l],q=sum[r]-sum[l];
			if(mi<abs(p-q)){
				break;
			}
			mi=abs(p-q);
			l++;
		}
		l--;
		f[r]=l;
	}
	g[n-2]=n-1;
	ll r=n-1;
	for(ll l=n-3;l>=2;l--){
		S=sum[n]-sum[r],R=sum[r]-sum[l],mi=abs(S-R);
		r--;
		while(l<r){
			S=sum[n]-sum[r],R=sum[r]-sum[l];
			if(mi<abs(S-R)){
				break;
			}
			mi=abs(S-R);
			r--;
		}
		r++;
		g[l]=r;
	}
	ll ans=inf;
	//cout<<g<<endl;
	FOR(i,2,n-1){
		p=sum[f[i]],q=sum[i]-sum[f[i]];
		R=sum[g[i]]-sum[i],S=sum[n]-sum[g[i]];
		//cout<<i<<endl;
		ll cnt=max({p,q,R,S})-min({p,q,R,S});
		//cout<<p<<' '<<q<<' '<<R<<' '<<S<<' '<<cnt<<endl;
		chmin(ans,cnt);
	}
	cout<<ans<<endl;
}