#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1e5+10;
int n, m;
ll a[MAX_N];

void solve()
{
	ll ans = 0;
	map<ll, ll> cnt;
    ll sum = 0;
    cnt[sum]=1;
	for(int i=1;i<=n;++i){
		(sum += a[i])%=m;
		ans+=cnt[sum];
		cnt[sum]++;
	}
	cout << ans << '\n';
}

int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;++i) cin >> a[i];
	solve();
	return 0;
}