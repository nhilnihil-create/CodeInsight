#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, int> P;
typedef pair<int, P> E;
#define MOD (1000000007ll)
#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	b += MOD;
	a += b;
	a %= MOD;
}

ll rwpw(ll a, ll p){
	ll ret = 1ll;
	while(p){
		if(p%2){
			mul_mod(ret,a);
		}
		mul_mod(a,a);
		p /= 2;
	}
	return ret;
}

int main(void){
	ll n,i,a[123456],c[123456],ans=0ll,tmp;
	c[0] = 0ll;
	cin >> n;
	for(i=0ll; i<n; ++i){
		c[i+1] = c[i];
		add_mod(c[i+1],rwpw(i+1,MOD-2));
	}
	for(i=0ll; i<n; ++i){
		cin >> a[i];
		tmp = (c[i+1]+c[n-i]+MOD-1)%MOD;
		mul_mod(tmp,a[i]);
		add_mod(ans,tmp);
	}
	for(i=0ll; i<n; ++i){
		mul_mod(ans,i+1);
	}
	cout << ans << endl;
	return 0;
}
