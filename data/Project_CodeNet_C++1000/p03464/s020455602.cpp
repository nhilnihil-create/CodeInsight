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

ll k, a[100008];

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> k;
	rep(i, 1, k){cin >> a[i];}
	
	ll ansmin = 2;
	ll ansmax = 2;
	rrep(i, k, 1){
		ll bufmax = a[i]*(ansmax/a[i])+a[i]-1;
		ll bufmin = a[i]*((ansmin+a[i]-1)/a[i]);
		if(bufmin <= bufmax){
			ansmax = bufmax;
			ansmin = bufmin;
		}
		else{
			print(-1)
			return 0;
		}
	}
	
	cout << ansmin << " " << ansmax << endl;
	return 0;
}