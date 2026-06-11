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
const ll 	MOD		=  	1e9 + 7;


// <------------- Declare Variables Here ------------> //

ll T = 1;
ll n, x, m, k;
string s, t;

// <------------- Implement Functions Here ----------> //

ll par[200000] = {}, cou[200000] = {};
ll ans[200000] = {};
ll u[200000] = {}, v[200000] = {};

ll find(ll x) {
	if (x == par[x]) return x;
	par[x] = find(par[x]);
	return par[x];
}

ll Union(ll x, ll y) {
	ll X = find(x);
	ll Y = find(y);

	par[Y] = X;

	ll val = cou[X] * cou[Y];

	cou[X] += cou[Y];
	cou[Y]  = cou[X];

	return val;
}

void print_par() {
	for (ll i = 1; i <= n; i++) {
		printf("%-2lld ", i);
	}
	printf("\n");
	for (ll i = 1; i <= n; i++) {
		printf("%-2lld ", par[i]);
	}
	printf("\n");
	for (ll i = 1; i <= n; i++) {
		printf("%-2lld ", cou[i]);
	}
	printf("\n\n");
}

// <------------- Start of main() -------------------> //

void MAIN() {
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) par[i] = i, cou[i] = 1;
	for (ll i = 1; i <= m; i++) {
		cin >> u[i] >> v[i];
	}

	ans[m] = n * (n - 1) / 2;
	for (ll i = m; i > 1; i--) {
		//print_par();
		if (find(u[i]) != find(v[i])) {
			ll val = Union(u[i], v[i]);
			ans[i - 1] = max(0ll, ans[i] - val);
		}
		else ans[i-1] = ans[i];
	}
	//print_par();

	for (ll i = 1; i <= m; i++) cout << ans[i] << "\n";
}

int main() {
	fastio; randomINT;
	//cin >> T;
	while (T--) {
		MAIN();
	}
	return 0;
}