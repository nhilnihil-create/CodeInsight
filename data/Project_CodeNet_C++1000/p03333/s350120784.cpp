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

ll n, l[100008], r[100008];

ll f(ll x){
	priority_queue<P> lq, rq;
	zep(i, 0, n){
		lq.push(P(l[i], i));
		rq.push(P(-r[i], i));
	}
	
	bool use[n];
	memset(use, 0, sizeof(use));
	
	ll ans = 0;
	ll at = 0;
	zep(i, 0, n){
		if(i%2 == x){
			while(!lq.empty() && use[lq.top().second]){
				lq.pop();
			}
			
			if(!lq.empty()){
				if(lq.top().first-at > 0){
					ans += lq.top().first-at;
					at = lq.top().first;
					use[lq.top().second] = true;
					lq.pop();
				}
			}
		}
		else{
			while(!rq.empty() && use[rq.top().second]){
				rq.pop();
			}
			
			if(!rq.empty()){
				if(at+rq.top().first > 0){
					ans += at+rq.top().first;
					at = -rq.top().first;
					use[rq.top().second] = true;
					rq.pop();
				}
			}
		}
		//print(ans)
	}
	return ans+abs(at);
}

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n;
	zep(i, 0, n){
		cin >> l[i] >> r[i];
	}
	
	print(max(f(0), f(1)))
	return 0;
}