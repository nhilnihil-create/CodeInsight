#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1110;
int N, M;
ll x[MAX_N];
ll y[MAX_N];
ll z[MAX_N];
ll tot[MAX_N];

void solve()
{
	ll ans = 0;
	for(int i=0;i<8;++i){
		memset(tot, 0, sizeof(tot));
		for(int j=0;j<N;++j){
			if(i>>0&1) tot[j]+=x[j]; else tot[j]-=x[j];
			if(i>>1&1) tot[j]+=y[j]; else tot[j]-=y[j];
			if(i>>2&1) tot[j]+=z[j]; else tot[j]-=z[j];
		}
		sort(tot,tot+N,greater<>());
		ans=max(ans, accumulate(tot,tot+M,0LL));
	}
	cout << ans << '\n';
}

int main()
{
	cin >> N >> M;
	for(int i=0;i<N;++i){
		cin >> x[i] >> y[i] >> z[i];
	}
	solve();
	return 0;
}