#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	ll N;
	cin >> N;
	ll c[5];
	rep(i,5) cin >> c[i];
	ll t = 1e15+1;
	rep(i,5) t = min(t, c[i]);
	ll ans = (N+t-1)/t + 4;
	cout << ans << endl;
	return 0;
}

