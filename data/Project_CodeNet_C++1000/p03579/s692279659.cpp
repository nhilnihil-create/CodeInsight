#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;

ll n, m, fl, cnt[5], v[100005];
vector<ll> gr[100005];

void f(ll p, ll q) {
	if(v[p]) {
		fl |= (v[p] != q);
		return;
	}
	v[p] = q;
	cnt[q]++;
	for(auto x:gr[p]) f(x, 3-q);
}

int main() {
	ll i, t1, t2;
	cin >> n >> m;
	for(i=0; i<m; i++) {
		scanf("%lld%lld", &t1, &t2);
		gr[t1].push_back(t2);
		gr[t2].push_back(t1);
	}
	f(1, 1);
	if(fl) cout << n * (n-1) / 2 - m;
	else cout << cnt[1] * cnt[2] - m;
	return 0;
}