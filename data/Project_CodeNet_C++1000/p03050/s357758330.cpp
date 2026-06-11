#include <bits/stdc++.h>
#define cout16 cout << setprecision(16) 
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define SORT(A) sort(A.begin(),A.end())
#define REV(A) reverse(A.begin(),A.end())
typedef long long int ll;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using P = std::pair<int,int>;
using vp = std::vector<P>;
using namespace std;
#define INF 1001001001
#define LL_INF 1001001001001001001
#define fi first
#define se second

vll divisor(ll n){
	vll res;
	for(ll i=1; i*i<=n; i++){
		if(n%i) continue;
		res.push_back(i);
		if(i*i!=n) res.push_back(n/i);
	}
	SORT(res);
	return res;
}

int main(void) {
	ll n; cin >> n;
	vll divis = divisor(n);
	ll ans = 0;
	for(auto di: divis){
		if(di==1) continue;
		ll m = di-1;
		if((n/m)==(n%m)) ans += m;
	}
	cout << ans << endl;
}


