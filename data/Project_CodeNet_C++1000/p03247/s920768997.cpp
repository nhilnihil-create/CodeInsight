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

ll x[1234],y[1234],u[1234],v[1234];

int main(void){
	int n,i,j,m=31;
	ll p,q;
	bool ev = false;
	cin >> n;
	for(i=0; i<n; ++i){
		cin >> x[i] >> y[i];
	}
	for(i=1; i<n; ++i){
		if(abs(x[i-1]+y[i-1])%2 != abs(x[i]+y[i])%2){
			cout << "-1" << endl;
			return 0;
		}
	}
	if(!((x[i-1]+y[i-1])%2)){
		ev = true;
	}
	for(i=0; i<n; ++i){
		u[i] = x[i]+y[i];
		v[i] = x[i]-y[i];
		if(ev){
			--u[i];
			--v[i];
		}
	}
	cout << (ev?(m+1):m) << endl;
	for(i=0; i<m; ++i){
		cout << ((i)?" ":"") << (1ll<<i);
	}
	if(ev){
		cout << " 1";
	}
	cout << endl;
	for(i=0; i<n; ++i){
		p = ((1ll<<31)-1-u[i])/2;
		q = ((1ll<<31)-1-v[i])/2;
		for(j=0; j<m; ++j){
			if((p&(1<<j)) && (q&(1<<j))){
				cout << "L";
			}else if(p&(1<<j)){
				cout << "D";
			}else if(q&(1<<j)){
				cout << "U";
			}else{
				cout << "R";
			}
		}
		if(ev){
			cout << "R";
		}
		cout << endl;
	}
	return 0;
}
