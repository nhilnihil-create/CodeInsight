#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const ll sz=1<<17;
ll n, lt=1, rt=1e9, md, ans, a[sz], tr[sz<<1];

void add(int p) {
	while(p < sz<<1) {
		tr[p]++;
		p += p & -p;
	}
}

int sum(int p) {
	ll res=0;
	while(p){
		res += tr[p];
		p -= p & -p;
	}
	return res;
}

bool f(int p){
	ll i, k, cnt=0;
	memset(tr, 0, sizeof(tr));
	for(i=1, k=sz; i<=n; i++) {
		add(k);
		k += a[i]>=p ? 1:-1;
		cnt += sum(k);
	}
	return cnt >= (n*(n+1)/2+1)/2;
}

int main() {
	scanf("%lld", &n);
	for(ll i=1; i<=n; i++) scanf("%lld", &a[i]);
	while(lt<=rt){
		md = lt+rt >> 1;
		if(f(md)) ans=md, lt=md+1;
		else rt=md-1;
	}
	printf("%lld", ans);
	return 0;
}