#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n;
string s;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n;
	ll a[n+1];
	rep(i, 1, n){
		cin >> a[i];
	}
	ll before = 0;
	ll ans = 0;
	rrep(i, n, 1){
		if(a[i] < before-1 || a[i] > i-1){
			ans = -1;
			break;
		}
		if(a[i] != before-1){
			ans += a[i];
		}
		before = a[i];
	}
	print(ans)
	return 0;
}