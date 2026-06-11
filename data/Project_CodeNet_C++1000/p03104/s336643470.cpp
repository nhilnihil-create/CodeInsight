#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

ll compute(ll n){
	ll ret = 0;
	for(int i = 1; i < 40; i++){
		ll tot = (1LL<<(i + 1));
		ll tmp = n%tot;
		if(tmp > (1LL<<i)){
			tmp -= (1LL<<i);
			ret += (tmp&1)*(1LL<<i);
		}
	}
	ll tmp = n%4;
	if(tmp == 2 || tmp == 3)ret++;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	ll a, b;
	cin>>a>>b;
	ll ans = compute(b + 1)^compute(a);
	cout<<ans<<endl;

	return 0;
}