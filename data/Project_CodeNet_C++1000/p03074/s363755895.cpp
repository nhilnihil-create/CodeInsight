//#include <bits/stdc++.h>
#include <stdio.h>
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
using ll=long long;
using intpair=pair<int,int>;
using intpv=vector<intpair>;
using llpair=pair<ll,ll>;
using llpv=vector<llpair>;
using intvec=vector<int>;
using llvec=vector<ll>;
using intq=queue<int>;
using llq=queue<ll>;
using intmat=vector<intvec>;
using llmat=vector<llvec>;
using pairmat=vector<llpv>;
#define matrix(T) vector<vector<T>>
#define PI 3.141592653589793
#define INTINF 1<<30
#define LLINF 1LL<<60
#define MPRIME 1000000007
#define MPRIME9 998244353
#define pqueue priority_queue
#define pushb push_back
#define fi first
#define se second
#define all(name) name.begin(),name.end()
#define rall(name) name.rbegin(),name.rend()
#define ABS(x) ( (x)>0 ? (x) : -(x) )
#define gsort(vbeg,vend) sort(vbeg,vend,greater<>())
#define init(v) for(auto &a_: v) cin>>a_
#define out(n) cout<<n<<endl

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
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

ll Fact(ll x, ll p) { //階乗
	ll f=1;
	for(ll i=2; i<=x; i++) {
		f*=i;
		f%=p;
	}
	return f;
}

ll nPr(ll n, ll r) {
	if(n<r) return 0;

	ll result=1LL;
	for(ll i=0; i<r; i++) result*=n-i;
	return result;
}

ll nPrP(ll n, ll r, ll p) { // mod pにおけるnPr
	if(n<r) return 0;

	ll result=1LL;
	for(int i=0; i<r; i++) {
		result*=n-i;
		result%=p;
	}
	return result;
}

ll nCr(ll n, ll r) {
	if (n == r) { return 1; }
	if (r > n) { return 0; }

	if (r > n / 2) { r = n - r; }

	if (n == 0) { return 0; }
	if (r == 0) { return 1; }
	if (r == 1) { return n; }

	double result = 1;
	for (double i = 1; i <= r; i++) {
		result *= (n - i + 1) / i;
	}

	return (ll)result;
}

int DigitNum(ll n) { //桁数
	int digit=0;
	ll wari=1LL;
	while(n/wari) {
		digit++;
		wari*=10;
	}
	return digit;
}

bool Palind(string s) { //回文判定
	return s == string(s.rbegin(), s.rend());
}


int N,K;
string S;
intvec v;
intvec sum;
int res=0;

void input() {
	cin>>N>>K>>S;
}

void solve() {
	v.pushb(0);
	bool sd=true;
	for(int i=0; i<N; i++) {
		if(sd) {
			if(S[i]=='0')
				v.back()++;
			else {
				sd=false;
				v.pushb(1);
			}
		}
		else {
			if(S[i]=='1')
				v.back()++;
			else {
				sd=true;
				v.pushb(1);
			}
		}
	}
	if(!sd) v.pushb(0);
	if(v.size()/2<K) {
		cout<<N<<endl;
		return;
	}

	sum.resize(v.size()+1,0);
	for(int i=1; i<sum.size(); i++) sum[i]=sum[i-1]+v[i-1];

	for(int i=0; 2*K+2*(i+1)<sum.size(); i++) {
		int mx=2*K+2*(i+1), mn=1+2*i;
		chmax(res,sum[mx]-sum[mn]);
	}
	chmax(res,sum[2*K]-sum[0]);
	chmax(res,sum[v.size()]-sum[v.size()-2*K]);

	cout<<res<<endl;
}

int main() {
	while(1) {
		input();
		solve();
		break;
	}
}
