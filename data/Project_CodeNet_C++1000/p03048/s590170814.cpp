#include <bits/stdc++.h>

#define f(i,a,b) for( ll i = a; i < b ; i++ ) 
#define af(i,a,b) for( ll i = a; i >= b ; i--)
#define rep(i,a,b,k) for(ll i = a; i < b ; i+= k )
#define arep(i,a,b,k) for( ll i = a; i >= b ; i-= k)
#define ones(x) (ll) __builtin_popcount(x);1
#define fs first
#define sc second
#define pb push_back
#define po pop_back
#define mp make_pair	
#define sz(a) (ll) a.size()
#define all(a) a.begin(), a.end()
#define sor(a) sort( a.begin(), a.end() )
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ller ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

using namespace std;
typedef long long ll;
typedef long double ld;	
typedef pair<ll,ll> ii ;
typedef vector<ll>  vi ;
typedef vector<ii> vii ;
	 
const ll MAX = 10000000;
const ll inf = 1e9;

int main() {
	fastio;
	ll R, G, B, n;
	cin >> R >> G >> B >> n;
	ll r, g, b, cont = 0;
	f(i,0,n+1){
	r = i;
	f(j,0,n+1){
	g = j;
	b = (n - r*R - g*G)/B;
	if(b >= 0 && n - r*R - g*G == b*B) cont++;
 	}
	}
	cout <<cont<<endl;
 
	return 0;
	}