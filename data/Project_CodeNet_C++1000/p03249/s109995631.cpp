#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
//#define mp make_pair
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll maxn = 1e5 + 10;
pair <ll, ll> d[maxn];
map <ll, ll> mp;
vector <ll> adj[maxn];
ll sz[maxn];
ll h[maxn];
bool mark[maxn];
ll n;

void dfs(int v){
	mark[v] = true;
	for(int i : adj[v]){
		if(!mark[i]){
			h[i] = h[v] + 1;
			dfs(i);
		}
	}
}

bool check(){
	dfs(d[n - 1].second);
	ll sum = 0;
	for(int i = 0; i < n; i ++){
		sum += h[i];
	}
//	cout << d[n - 1].second << endl;
	if(sum != d[n - 1].first)
		return false;
	else
		return true;
}

int main(){
	fast_io;
	cin >> n;
	for(ll i = 0; i < n; i ++){
		ll x;
		cin >> x;
		d[i] = {x, i};
//		s.insert({-x, i});
		mp[x] = i; 
	}
	sort(d, d + n);
	reverse(d, d + n);
	bool flag = true;
	
	for(ll i = 0; i < n - 1; i ++){
		sz[d[i].second] = 1;
		for(ll u : adj[d[i].second]){
			sz[d[i].second] += sz[u];
		}
		ll x = d[i].first + sz[d[i].second] * 2 - n;
		auto f = mp.find(x);
		if(f == mp.end()){ 
			flag = false;
			break;
		}else{
			adj[mp[x]].pb(d[i].second);
		}
//		cout << "x = " << x << endl;
	}
	
	flag = check();
	
	if(flag){
		for(ll i = 0; i < n; i ++){
			for(ll u : adj[i]){
				cout << i + 1 << " " << u + 1 << endl;
			}
		}
	}else{
		cout << -1 << endl;
	}
	
	return 0;
}

