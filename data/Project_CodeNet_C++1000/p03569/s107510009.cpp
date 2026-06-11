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

int main(void){
	int n,l,r,ans=0;
	string s;
	cin >> s;
	l = 0; r = s.l_ength()-1;
	while(l<r){
		if(s[l]==s[r]){
			++l; --r;
		}else if(s[l]=='x'){
			++ans; ++l;
		}else if(s[r]=='x'){
			++ans; --r;
		}else{
			cout << "-1" << endl;
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}
