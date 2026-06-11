#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, int> P;
typedef pair<ll, P> E;
#define MOD (1000000007ll)
#define l_ength size
#define PI 3.14159265358979

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	b += MOD;
	a += b;
	a %= MOD;
}

ll root(ll x){
	ll l,r,m;
	l = 0ll;
	r = (1ll<<31);
	while((r-l)>1){
		m = (r+l)/2;
		if(m*m > x){
			r = m;
		}else{
			l = m;
		}
	}
	return ((r*r)>x)?l:r;
}

int main(void){
	int i,q;
	ll a,b,c;
	cin >> q;
	for(i=0; i<q; ++i){
		cin >> a >> b;
		c = root(a*b);
		if(a*b == c*c && a!=b){
			cout << (2*c-3) << endl;
		}else if(c*(c+1)>=a*b){
			cout << (2*c-2) << endl;
		}else{
			cout << (2*c-1) << endl;
		}
	}
	return 0;
}
