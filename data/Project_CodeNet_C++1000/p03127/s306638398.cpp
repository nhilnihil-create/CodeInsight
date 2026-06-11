#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n;
	cin >> n;
	ll ans;
	cin >> ans;
	for(int i=1; i<n; i++){
		ll a;
		cin >> a;
		ans = gcd(ans,a);
	}
	
	cout << ans << endl;
	return 0;
}