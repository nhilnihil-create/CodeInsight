#include <bits/stdc++.h>

#define f(i,a,b) for( ll i = a; i < b ; i++ ) 
#define af(i,a,b) for( ll i = a; i >= b ; i--)
#define rep(i,a,b,k) for(ll i = a; i < b ; i+= k )
#define arep(i,a,b,k) for( ll i = a; i >= b ; i-= k)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(a) (ll) a.size()
#define all(a) a.begin(), a.end()
#define sor(a) sort( a.begin(), a.end() )
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ller ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
 
const ll MAX = 3e5 + 100;
const ll inf = 1e9;
const ll mod = 1e9 + 7;

ll a[20][20],c[1LL<<18],dp[1LL << 18];
int main(){
	fastio;
	ll tc,x,n,m;
	tc = 1;
	cin >> n;
	f(i,0,n) f(j,0,n) cin >> a[i][j];
	f(mask,1,1LL<<n){
		ll aux = 0;
		f(i,0,n) f(j,0,n) if( (mask &  (1LL<<i) )  &&  ( mask &  (1LL<<j)  ) ) aux +=a[i][j];
		c[mask] = aux>>1; 
	}
	f(mask,1,1LL << n){
		for(ll submask = mask; submask > 0; submask = (submask-1)& mask)
			dp[mask] = max(dp[mask],c[submask] + dp[mask^submask]);
	}
	cout << dp[(1LL << n) - 1]<< endl;
	return 0;
}