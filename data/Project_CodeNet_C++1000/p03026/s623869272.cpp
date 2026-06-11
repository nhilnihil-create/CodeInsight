#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define N 10005
using namespace std;
typedef long long ll;

ll n, k, sum, mx, a[N], ans[N];
vector<ll> gr[N];
queue<ll> qu;
int main() {
	ll i, t, u, v;
	cin>> n;
	for(i=0; i<n-1; i++) {
		scanf("%lld%lld", &u, &v);
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	for(i=0; i<n; i++) {
		scanf("%lld", &a[i]);
		sum += a[i];
		mx = max(mx, a[i]);
	}
	cout<< sum-mx<< endl;
	sort(a, a+n, greater<int>());
	qu.push(1);
	while(!qu.empty()) {
		t = qu.front(); qu.pop();
		ans[t] = a[k++];
		for(auto x: gr[t]) {
			if(!ans[x]) qu.push(x);
		}
	}
	for(i=1; i<=n; i++) printf("%lld ", ans[i]);
	return 0;
}
