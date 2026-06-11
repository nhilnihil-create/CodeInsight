#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	ll n;
	cin >> n;
	vector<vector<ll>> G(n);
	
	ll a, b; 
	rep(i, 1, n-1){
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	ll dst[n];
	memset(dst, -1, sizeof(dst));
	dst[0] = 0;
	queue<ll> q;
	q.push(0);
	ll l = 0;
	while(!q.empty()){
		ll at = q.front(); q.pop();
		zep(i, 0, G[at].size()){
			if(dst[G[at][i]] == -1){
				dst[G[at][i]] = dst[at]+1;
				l = G[at][i];
				q.push(G[at][i]);
			}
		}
	}
	
	memset(dst, -1, sizeof(dst));
	dst[l] = 0;
	q.push(l);
	ll lr = 0;
	while(!q.empty()){
		ll at = q.front(); q.pop();
		zep(i, 0, G[at].size()){
			if(dst[G[at][i]] == -1){
				dst[G[at][i]] = dst[at]+1;
				lr = dst[G[at][i]];
				q.push(G[at][i]);
			}
		}
	}
	
	if(lr%3 == 1){
		print("Second")
	}
	else{
		print("First")
	}
	return 0;
}