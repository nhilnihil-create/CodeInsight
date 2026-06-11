#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

const int MAXN = 1e5 + 5;
int n, par[MAXN], mn;
ll d, sz[MAXN], h[MAXN], sum = 0;
map <ll, ll> mp;
vector <int> adj[MAXN];
bool can = false, mark[MAXN];
vector <pair<ll, int>> v;

void dfs(int v, int parv){
	mark[v] = true;
	sum += h[v];
	for(auto u: adj[v]){
		if(!mark[u]){
			h[u] = h[v] + 1ll;
			dfs(u, v);
		}
		else if(u != parv)
			can = true;
	}
	return;
}

bool check(){
	for(int i = 1; i <= n; i++)
		if(i != mn && (par[i] < 1 || par[i] > n)){
			return true;
		}
	dfs(mn, -1);
	for(int i = 1; i <= n; i++)
		if(!mark[i])
			can = true;
	if(sum != -v[n - 1].first)
		can = true;
	return can;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> d; sz[i] = 1ll;
		mp[d] = i;
		v.push_back({-d, i});
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n - 1; i++){
		d = -v[i].first;
		ll ind = v[i].second;
		ll dpar = d + (2ll * sz[ind]) - (ll)n;
		if(!mp[dpar] || mp[dpar] == ind){
			cout << -1 << endl;
			return 0;
		}
		par[ind] = mp[dpar];
		sz[par[ind]] += sz[ind];
		adj[par[ind]].push_back(ind);
		adj[ind].push_back(par[ind]);
	}
	mn = v[n - 1].second;
	if(check()){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < n - 1; i++){
		cout << par[v[i].second] << " " << v[i].second << '\n';
	}
	return 0; 
}
