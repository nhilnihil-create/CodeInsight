#include <bits/stdc++.h>
using namespace std;

template<typename T, typename U>
using pv=vector<pair<T,U>>;
template<typename T>
using matrix=vector<vector<T>>;
template<typename T>
using pque=priority_queue<T>;
template<typename T>
using lpque=priority_queue<T,vector<T>,greater<T>>;

using ll=long long;
using intpair=pair<int,int>;
using llpair=pair<ll,ll>;
using ilpair=pair<int,ll>;
using lipair=pair<ll,int>;
using intvec=vector<int>;
using llvec=vector<ll>;
using intq=queue<int>;
using llq=queue<ll>;
using intmat=vector<intvec>;
using llmat=vector<llvec>;

#define PI 3.141592653589793
#define INTINF 1<<30
#define LLINF 1LL<<60
#define MPRIME 1000000007
#define MPRIME9 998244353
#define MMPRIME (1ll<<61)-1

#define len length()
#define pushb push_back
#define fi first
#define se second

#define setpr fixed<<setprecision(15)
#define all(name) name.begin(),name.end()
#define rall(name) name.rbegin(),name.rend()
#define gsort(vbeg,vend) sort(vbeg,vend,greater<>())

template<class T>
inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<class T>
inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template<class T>
inline void outmat(T& a, int y, int x) {
	for(int i=0; i<y; i++) {
		for(int j=0; j<x; j++) cout<<a[i][j]<<" ";
		cout<<endl;
	}
}

template<class T>
inline void init(T& v) {
	for(auto &a: v) cin>>a;
}
template<class T, class U>
inline void init(vector<pair<T,U>>& v) {
	for(auto &a: v) cin>>a.first>>a.second;
}
template<class T, class N>
inline void init(T& v, N n) {
	v.resize(n);
	for(auto &a: v) cin>>a;
}
template<class T, class U, class N>
inline void init(vector<pair<T,U>>& v, N n) {
	v.resize(n);
	for(auto &a: v) cin>>a.first>>a.second;
}

template<class N>
void resiz(N n) {
	//empty
}
template<class N, class T, class... U>
void resiz(N n, T&& hd, U&&... tl) {
	hd.resize(n);
	resiz(n,forward<U>(tl)...);
}

ll binpow(ll a, ll ex, ll p) { //繰り返し二乗法
	ll result=1;
	while(ex>0) {
		if(ex&1) result=result*a%p;
		ex>>=1;
		a=a*a%p;
	}
	return result;
}


int N;
int D[13];
int res=0;

void input() {
	cin>>N;
}

void solve() {
	D[0]=2; D[12]=1;
	for(int i=0; i<N; i++) {
		int d; cin>>d;
		D[d]++;
		if(D[d]>2) {
			cout<<0<<endl;
			return;
		}
	}

	for(int bit=0; bit<(1<<24); bit++) {
		if(!(bit&1)) continue;
		if((D[12]==2) ^ ((bit>>12)&1)) continue;
		bool fault=false;
		for(int i=1; i<12; i++) {
			switch(D[i]) {
				case 0: {
					if((bit>>i)&1 || (bit>>(24-i))&1) fault=true;
					break;
				}
				case 1: {
					if(!( ((bit>>i)&1) ^ ((bit>>(24-i))&1) )) fault=true;
					break;
				}
				case 2: {
					if(!((bit>>i)&1) || !((bit>>(24-i))&1) ) fault=true;
					break;
				}
				default: {
					cout<<-1<<endl;
					return;
				}
			}
			if(fault) break;
		}
		if(fault) continue;

		int restmp=24;
		int tmp=0;
		for(int i=1; i<=24; i++) {
			tmp++;
			if((bit>>(i%24))&1) {
				chmin(restmp,tmp);
				tmp=0;
			}
		}
		chmax(res,restmp);
	}
	cout<<res%24<<endl;
}

int main() {
	int t=1;
	while(t) {
		input();
		solve();
		t--;
	}
}
