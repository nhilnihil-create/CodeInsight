#include <bits/stdc++.h>
typedef long long ll;
#define reps(i,s,n) for(ll (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define All(x) (x).begin(),(x).end()
using namespace std;

signed main() {
	ll N,K;
	cin >> N >> K;
	vector<ll> A(N);

	vector<ll> bitadd(63, 0);
	for(auto &a : A) cin >> a;
	for(ll j=0;j<63;j++) {
		ll cnt1 = 0;
		for(int i=0;i<N;i++) {
			if(A[i] & (1LL << j)) cnt1++;
		}
		ll cnt0 = N - cnt1;
		if(cnt0 > cnt1) {
			bitadd[j] = (1LL << j) * (cnt0 - cnt1);
		}
	}

	ll ans = 0;
	ll asum = accumulate(A.begin(), A.end(), 0LL);
	ll pre = 0;

	for(ll i=62;i>=0;i--) {
		if(K & (1LL << i)) {
			ll tmpsum = asum;
			for(ll j=0;j<i;j++) tmpsum += bitadd[j];
			tmpsum += pre;
			ans = max(ans, tmpsum);
			pre += bitadd[i];
		}
	}
	ans = max(ans, pre + asum);
	cout << ans << endl;
}