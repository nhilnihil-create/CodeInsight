#include <bits/stdc++.h>
using namespace std;
const int maxn = 234567;
const long long lim = (1ll<<62) - 1;
long long add(long long a, long long b){
	a += b;
	if(a >= lim) a = lim;
	return a;
}
long long slow_mul(long long a, long long b){
	long long r = 0;
	for(; b; a = add(a, a), b >>= 1) if(b&1) r = add(r, a);
	return r;
}
long long x[maxn], val[maxn];
int main(){
	int n, X; cin >> n >> X;
	for(int i = 0; i < n; i++) cin >> x[i];
	for(int i = 1; i < n; i++) x[i] += x[i - 1];
	val[1] = 5;
	for(int i = 2; i <= n; i++) val[i] = 2 * i + 1;
	auto get = [&](int i, int j){
		long long ans = x[j];
		if(i - 1 >= 0) ans -= x[i - 1];
		return ans;
	};
	long long ans = lim + lim;
	for(int i = 1; i <= n; i++){
		long long now = 0;
		int pt = n - 1, bl = 0;
		for(int j = 1; pt >= 0; j++, pt -= i){
			long long here = get(pt - i + 1, pt);
			now = add(now, slow_mul(here, val[j]));
			bl++;
		}
		now = add(now, slow_mul(i, X));
		ans = min(ans, now);
	}
	cout << ans + slow_mul(n, X) << endl;
	return 0;
}
