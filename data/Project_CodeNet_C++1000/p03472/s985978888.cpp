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

	int n, h;
	cin>>n>>h;
	int a = 0;
	vector<int> b(n);
	for(int i = 0; i < n; i++){
		int x; cin>>x>>b[i];
		a = max(a, x);
	}
	sort(b.rbegin(), b.rend());
	ll ans = h;
	ll sum = 0;
	for(int i = 0; i < n; i++){
		sum += b[i];
		ll req = max(0LL, h - sum);
		ans = min(ans, i + 1 + (req + a - 1)/a);
	}
	cout<<ans<<'\n';

	return 0;
}