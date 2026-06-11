#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	ll n, m;
	cin>>n>>m;
	ll ans = 1;
	for(ll k = 1; k*k <= m; k++){
		if(m%k == 0){
			if(m/k >= n)ans = max(ans, k);
			if(k >= n)ans = max(ans, m/k);
		}
	}
	cout<<ans<<endl;

	return 0;
}