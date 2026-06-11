
#include<bits/stdc++.h>
using namespace std;

#define fastio 			ios::sync_with_stdio(0);	cin.tie(0); cout.tie(0);  cout<<fixed;  cout<<setprecision(12);
#define randomINT 		mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define	newl 			cout<<"\n"
#define DISP(as)		for(auto it : as) cout<<it<<" ";newl;
#define all(x)         	(x).begin(),(x).end()
#define mset(x,val)    	memset(x,val,sizeof(x))
#define newl           	cout<<"\n"
#define pb             	push_back
#define mp             	make_pair
#define f 				first
#define s 				second
#define dline          cerr<<"///REACHED///\n";
#define deb1(x)        cerr<<#x<<" = "<<x<<'\n';
#define deb2(x,y)      cerr<<'['<<#x<<','<<#y<<"] = "<<'['<<x<<','<<y<<']'<<'\n';
#define deb3(x,y,z)    cerr<<'['<<#x<<','<<#y<<','<<#z<<"] = "<<'['<<x<<','<<y<<','<<z<<']'<<'\n';

typedef long long 				ll;
typedef long double 			ld;
typedef vector<ll> 				vll;
typedef pair<ll , ll> 			pll;
typedef pair<ld, ld> 			pld;
typedef unordered_map<ll, ll> 	um;
typedef vector<pll> 			vpll;

const ll 	MAX5 	= 	1e+5 + 7;
const ll 	MAX7 	= 	1e+7 + 7;
const ll 	MAXN 	= 	MAX7;
const ll   	INF   	=  	0x7f7f7f7f7f7f7f7f;
const int  	INFi 	=  	0x7f7f7f7f;
const ll 	MOD		=  	1000000007;

// <------------- Declare Variables Here ------------> //

ll T = 1;
ll n, q, x, K;
string s,t;

// <------------- Implement Functions Here ----------> //

// <------------- Start of main() -------------------> //

void MAIN() {
	cin>>n;
	vll a(n),b(n),c(n);

	for(ll i=0;i<n;i++) cin>>a[i];
	for(ll i=0;i<n;i++) cin>>b[i];
	for(ll i=0;i<n;i++) cin>>c[i];

	ll ans = 0;
	sort(all(a));
	sort(all(c));

	for(ll i=0;i<n;i++) {

		ll val = b[i];
		ll prod = 1;
		ll l = -1, r = n-1;
		ll m;

		while(l < r) {
			m = (l+r + 1)/2;

			if(a[m] < val) {
				l = m;
			}
			else {
				r = m-1;
			}
		}

		prod*=(l+1);

		l=0,r= n;

		while(l < r) {
			m = (l+r)/2;

			if(c[m] > val) {
				r = m;
			}
			else {
				l = m+1;
			}
		}

		prod*= (n-l);

		ans+=prod;
	}

	cout<<ans;

}


int main() {
	fastio; randomINT;
	//cin >> T;
	while (T--) {
		MAIN();
	}
	return 0;
}
