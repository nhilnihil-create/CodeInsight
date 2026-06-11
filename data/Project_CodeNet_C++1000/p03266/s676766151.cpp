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

	int n, k;
	cin>>n>>k;
	if(k&1){
		cout<<(n/k)*1LL*(n/k)*(n/k)<<endl;
	}else{
		ll ans = (n/k)*1LL*(n/k)*(n/k);
		ll tmp = n/(k/2) - n/k;
		ans += tmp*tmp*tmp;
		cout<<ans<<endl;
	}

	return 0;
}