#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	pair <ll,ll> p[N];
	rep(i,N) {
		int a, b;
		cin >> a >>b;
		p[i] = make_pair(a,b);
	}

	sort(p,p+N);
	ll ans = 0;
	ll tot = 0;
	rep(i,N) {
		ans += p[i].first*min(p[i].second, M-tot);
		tot += min(p[i].second, M-tot);
		if (tot == M) break;
	}
	cout << ans << endl;
	return 0;
}
