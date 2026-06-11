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
	
	ll n, k, q;
	cin >> n >> k >> q;
	ll a[n];
	zep(i, 0, n){cin >> a[i];}
	
	bool use[n+1];
	memset(use, 0, sizeof(use));
	use[n] = true;
	
	vector<P> pos;
	zep(i, 0, n){pos.push_back(P(a[i], i));}
	sort(pos.begin(), pos.end());
	
	ll ans = INF;
	zep(i, 0, n){
		priority_queue<ll> pq;	
		
		ll l = 0;	
		rep(r, 0, n){
			if(use[r]){
				if(r-l >= k){
					priority_queue<ll> tmp;
					zep(j, l, r){tmp.push(-a[j]);}
					rep(j, 1, r-l-k+1){pq.push(tmp.top()); tmp.pop();}
				}
				l = r+1;
			}
		}
		
		//print(pq.size())
		if(pq.size() >= q){
			ll buf = pq.top();
			rep(i, 1, q-1){pq.pop();}
			buf -= pq.top();
			ans = min(buf, ans);
		}
		else{
			break;
		}
		
		use[pos[i].second] = true;
	}
	print(ans)
	return 0;
}