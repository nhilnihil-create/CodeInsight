#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

int ufr[225816],ufp[225816];
ll a[225816],b[225816];

void ufinit(int n){
	int i;
	for(i=0; i<n; ++i){
		ufp[i] = i;
		ufr[i] = 1;
	}
}

int ufind(int x){
	if(x == ufp[x]){
		return x;
	}
	ufp[x] = ufind(ufp[x]);
	return ufp[x];
}

void unionf(int x, int y){
	x = ufind(x);
	y = ufind(y);
	if(x==y){
		return;
	}
	if(ufr[x] < ufr[y]){
		swap(x,y);
	}
	ufp[y] = x;
	ufr[x] += ufr[y];
}

int main(void){
	int n,m,u,v,i;
	ll ans = 0ll;
	cin >> n >> m;
	ufinit(n*2);
	for(i=0; i<m; ++i){
		cin >> u >> v;
		--u; --v;
		unionf(u,v+n); --ans;
		unionf(v,u+n); --ans;
	}
	for(i=0; i<n; ++i){
		++a[ufind(i)];
		++b[ufind(i+n)];
		if(ufind(i)==ufind(i+n)){
			--ans;
		}
	}
	for(i=0; i<n; ++i){
		ans += a[i]*b[i];
		ans += a[i+n]*b[i+n];
	}
	cout << (ans>>1) << endl;
	return 0;
}
