#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

ll compute(vector<ll> &a, ll x){
	ll ret = 0;
	for(auto y : a){
		ret += abs(x - y);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n; cin>>n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++){
		cin>>a[i]; a[i] -= i;
	}
	sort(a.begin(), a.end());
	ll ans = compute(a, a[n/2]);
	if(n%2 == 0)ans = min(ans, compute(a, a[n/2 - 1]));
	cout<<ans<<endl;

	return 0;
}