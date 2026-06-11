#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
const ll N = 100005;

ll n, d[N], cnt[N], rd[N];
map<ll,ll> dti, itd;
vector<ll> adj[N];
vector<pll> ans;

void dfs1 (ll I) {
	for(auto &T : adj[I]) {
		dfs1(T);
		rd[I] += rd[T] + cnt[T];
	}
}

void dfs2 (ll I) {
	for(auto &T : adj[I]) {
		rd[T] = rd[I] - cnt[T] + (n-cnt[T]);
		dfs2(T);
	}
}

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) {
		scanf("%lld",&d[i]);
		dti[d[i]] = i;
		itd[i] = d[i];
	}
	sort(d+1, d+1+n);
	for(ll i=n;i>=2;i--) {
		ll I = dti[d[i]];
		ll C = ++cnt[I];
		ll J = dti[d[i] - (n-C) + C];
		if(J == 0) {
			puts("-1");
			return 0;
		}
		ans.push_back({I, J});
		cnt[J] += cnt[I];
		adj[J].push_back(I);
	}
	ll R = dti[d[1]];
	dfs1(R);
	dfs2(R);
	for(ll i=1;i<=n;i++) {
		if(itd[i] != rd[i]) {
			puts("-1");
			return 0;
		}
	}
	for(auto &T : ans) {
		printf("%lld %lld\n", T.X, T.Y);
	}
}
