#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<double, ll> P;
typedef pair<ll, P> E;
#define MOD (1000000007ll)
#define l_ength size
#define EPS (1e-10)

void add_mod(ll &a, ll b){
	a += b;
	a %= MOD;
}

void mul_mod(ll &a, ll b){
	a *= b;
	a %= MOD;
}

ll ds(ll x){
	return ((x<10)?x:x%10+ds(x/10));
}

bool comp(P a, P b){
	return (a.first == b.first)?(a.second < b.second):(a.first < b.first);
}

vector<P> v;

int main(void){
	ll k,i,t=1ll,b=0ll,j,x,y,p=0ll;
	for(i=1ll; i<1000; ++i){
		x = i;
		y = ds(i);
		for(j=0; j<15; ++j){
			v.push_back(P((double)(x)/y,x));
			x *= 10;
			x += 9;
			y += 9;
		}
	}
	sort(v.begin(),v.end(),comp);
	cin >> k; i=0;
	while(k){
		if(v[i].second > p){
			p = v[i].second;
			cout << p << endl;
			--k;
		}
		++i;
	}
	return 0;
}
