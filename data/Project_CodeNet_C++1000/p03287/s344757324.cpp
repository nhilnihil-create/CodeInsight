#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N;
	ll M;
	cin >> N >> M;
	vector<ll> A(N);
	for(auto &a: A) cin >> a;
	vector<ll> B(N, 0);
	B[0] = A[0];
	for(int i=1;i<N;i++) {
		B[i] = A[i] + B[i-1];
	}
	map<ll,ll> rest;
	for(int i=0;i<N;i++) {
		rest[B[i]%M]++;
	}
	ll ans = 0;
	for(auto &tmp : rest) {
		ll num = tmp.first;
		ll cnt = tmp.second;
		if(num == 0) ans += cnt;
		ans += cnt*(cnt-1)/2;
	}
	cout << ans << endl;
}