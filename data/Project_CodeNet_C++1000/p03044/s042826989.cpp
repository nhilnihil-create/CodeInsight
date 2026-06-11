#include<bits/stdc++.h>
#include<string>
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define mod (ll)(1e9+7)
#define nax (ll)(1e5)
#define INFL LLONG_MAX
#define NINFL LLONG_MIN
#define INF INT_MAX
#define disp(a,n,arr) for(int i=a;i<(ll)n;i++) cout << arr[i] << " "; cout << "\n";
#define check cout << "Working\n";
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vpl vector<pl>
#define vpi vector<pi>
#define vb vector<bool>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(),a.end()
using namespace std;

int main() {
	FIO;
	int t = 1;
	//cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector<pl> adj[n+1];
		for(int i=0;i<n-1;i++){
			ll a,b,c;
			cin >> a >> b >> c;
			adj[a].pb(mp(b,c));
			adj[b].pb(mp(a,c));
		}
		vl dist(n+1,0);
		vb vis(n+1,false);
		queue<ll> q;
		q.push((ll)1);
		vis[1] = true;
		while(!q.empty()){
			ll v = q.front();
			q.pop();
			for(auto u:adj[v]){
				if(!vis[u.fi]){
					vis[u.fi] = true;
					dist[u.fi] = dist[v] + u.se;
					q.push(u.fi); 
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(dist[i]&1) cout << "1\n";
			else cout << "0\n";
		}
	}


	return 0;
}
