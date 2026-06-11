#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

ll func(ll n){
	if((n+1)%2==0){
		if((n+1)%4==0){
			return 0;
		}else{
			return 1;
		}
	}else{
		if((n+1)%4==1){
			return n;
		}else{
			return n^1;
		}
	}
}

int main(){
	ll a,b;
	cin >> a >> b;

	a = max((ll)0, a-1);
	
	ll ansa = func(a);
	ll ansb = func(b);
	
	cout << (ansa^ansb) << endl;
	
	return 0;
}