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
	
	ll h, w, n, x, y;
	vector<P> v;
	cin >> h >> w >> n;
	zep(i, 0, n){
		cin >> x >> y;
		v.push_back(P(y, x));
	}
	v.push_back(P(1, h+1)); n++;
	sort(v.begin(), v.end());
	
	ll ans = INF;
	ll sx = 1;
	ll sy = 1;
	ll t = 0;
	zep(i, 0, n){
		x = v[i].second;
		y = v[i].first;
		if(x-sx > y-sy){
			ans = min(x-1, ans);
		}
		if(x-sx == y-sy){
			sx = x;
			sy = y-1;
		}
	}
	print(ans)
	return 0;
}