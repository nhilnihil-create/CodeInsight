#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1e5+10;
int A, B, Q;
ll s[MAX_N],t[MAX_N],x[MAX_N];

void solve()
{
	sort(s,s+A);sort(t,t+B);
	for(int i=0;i<Q;++i){
		ll at=x[i];
		int nxt_s = lower_bound(s,s+A,at)-s;
		int nxt_t = lower_bound(t,t+B,at)-t;
		int prv_s = nxt_s ? nxt_s-1 : -1;
		int prv_t = nxt_t ? nxt_t-1 : -1;
		if(nxt_s == A) nxt_s = -1;
		if(nxt_t == B) nxt_t = -1;
		ll ans = 1e18;
		if(nxt_s!=-1&&nxt_t!=-1) ans=min(ans,max(s[nxt_s],t[nxt_t])-at);
		if(nxt_s!=-1&&prv_t!=-1) ans=min(ans,min(s[nxt_s]-at, at-t[prv_t])+s[nxt_s]-t[prv_t]);
		if(prv_s!=-1&&prv_t!=-1) ans=min(ans,at-min(s[prv_s],t[prv_t]));
		if(prv_s!=-1&&nxt_t!=-1) ans=min(ans,min(t[nxt_t]-at, at-s[prv_s])+t[nxt_t]-s[prv_s]);
		cout << ans << '\n';
	}
}

int main()
{
	cin >> A >> B >> Q;
	for(int i=0;i<A;++i) cin >> s[i];
	for(int i=0;i<B;++i) cin >> t[i];
	for(int i=0;i<Q;++i) cin >> x[i];
	solve();
	return 0;
}