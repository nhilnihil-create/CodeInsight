#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n, m, a, b, p, root, ans[100008];

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n >> m;
	vector<ll> edge[n+1];
	set<ll> redge[n+1];
	rep(i, 1, n-1+m){
		cin >> a >> b;
		edge[a].push_back(b);
		redge[b].insert(a);
	}
	
	rep(i, 1, n){if(redge[i].size() == 0){p = i;}}
	ans[p] = 0;
	
	queue<ll> q;
	q.push(p);
	while(!q.empty()){
		ll at = q.front();
		q.pop();
		for(ll i = 0; i < edge[at].size(); i++){
			ll nx = edge[at][i];
			if(redge[nx].size() > 1){
				redge[nx].erase(at);
			}
			else{
				q.push(nx);
				ans[nx] = at;
			}
		}
	}
	
	rep(i, 1, n){
		print(ans[i])
	}
	return 0;
}