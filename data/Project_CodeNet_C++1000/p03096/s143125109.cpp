//#include <bits/stdc++.h>
//#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <tuple>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>

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
	for(auto &a__: v) cin>>a__;
}
template<class T, class U>
inline void init(vector<pair<T,U>>& v) {
	for(auto &a__: v) cin>>a__.first>>a__.second;
}
template<class T, class N>
inline void init(T& v, N n) {
	v.resize(n);
	for(auto &a__: v) cin>>a__;
}
template<class T, class U, class N>
inline void init(vector<pair<T,U>>& v, N n) {
	v.resize(n);
	for(auto &a__: v) cin>>a__.first>>a__.second;
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

ll GCD(ll a, ll b) { //最大公約数
	if(a==0||b==0) return 0;
	if(a<b) swap(a,b);
	ll tmp = a%b;
	while(tmp!=0) {
		a = b;
		b = tmp;
		tmp = a%b;
	}
	return b;
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
int pos[200001];
ll res[200001];

void input() {
	res[0]=1;

	cin>>N;
}

void solve() {
	for(int i=1; i<=N; i++) {
		int clr; cin>>clr;
		int cpos=pos[clr];
		res[i]=res[i-1];
		if(cpos && i-cpos>1) {
			res[i]=(res[i]+res[cpos])%MPRIME;
		}
		pos[clr]=i;
	}
	cout<<res[N]<<endl;
}

int main() {
	while(1) {
		input();
		solve();
		break;
	}
}
